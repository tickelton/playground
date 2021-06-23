#!/usr/bin/env python3

# Copyright (c) 2021 tick <tickelton@gmail.com>
# SPDX-License-Identifier:	MIT

import sys
import importlib
import argparse
import random
import time
import pandas
import sqlite3
import http.cookiejar
import urllib.parse
import urllib.request
from datetime import datetime

PROGNAME="scrape-o-mat"
VERSION="0.0.1"
WAIT_S_MIN = 15
WAIT_S_MAX = 45

def do_random_wait():
    wait_time = random.randint(WAIT_S_MIN, WAIT_S_MAX);
    print("Wating for {} seconds.".format(wait_time))
    time.sleep(wait_time)

def do_post_request(op, cfg, step):

    post_data = urllib.parse.urlencode(cfg[step]["post_data"])
    post_data = post_data.encode('ascii')
    op.addheaders = [('User-Agent', cfg["user_agent"])]
    rc = 0
    try:
        res = op.open(cfg[step]["url"], post_data)
        rc = res.getcode()
    except urllib.request.HTTPError as e:
        rc = e.code
        print(str(e))
    except OSError as e:
        print(str(e))

    data = None
    if rc == 200:
       data = res.read()

    res.close()

    return (rc, data)

def do_get_request(op, cfg, step):

    op.addheaders = [('User-Agent', cfg["user_agent"])]
    rc = 0
    try:
        res = op.open(cfg[step]["url"])
        rc = res.getcode()
    except urllib.request.HTTPError as e:
        rc = e.code
        print(str(e))
    except OSError as e:
        print(str(e))

    data = None
    if rc == 200:
       data = res.read()

    res.close()

    return (rc, data)

def main():
    parser = argparse.ArgumentParser(prog=PROGNAME)
    parser.add_argument('--version', action='version', version='%(prog)s v' + VERSION)
    parser.add_argument('config_module', metavar='CONFIG', type=str, nargs=1,
                                help='configuration module name')
    args = parser.parse_args()

    cfg = importlib.import_module(args.config_module[0]).configuration

    if not "fetch" in cfg or not "url" in cfg["fetch"]:
        print("Error: config data is missing 'fetch' URL. Aborting.")
        sys.exit(1)

    cookie_jar = http.cookiejar.CookieJar()
    op = urllib.request.build_opener(urllib.request.HTTPCookieProcessor(cookie_jar))

    # execute login
    if "login" in cfg:
        if "post_data" in cfg["login"]:
            (rc, data) = do_post_request(op, cfg, "login")
            if rc == 200:
                print("Login successful.")
            else:
                print("Login failure!")
                op.close()
                sys.exit(1)

    # wait for a random number of seconds to appear more human
    do_random_wait()

    # fetch data
    if "post_data" in cfg["fetch"]:
        (rc, data) = do_post_request(op, cfg, "fetch")
        if rc == 200:
            print("Fetch successful.")
            dfs = pandas.read_html(data)
        else:
            print("Fetch failure!")
            op.close()
            sys.exit(1)

    # more random delay
    do_random_wait()

    # execute logout
    if "logout" in cfg:
        if "post_data" in cfg["logout"]:
            (rc, data) = do_post_request(op, cfg, "logout")
        else:
            (rc, data) = do_get_request(op, cfg, "logout")
        if rc == 200:
            print("Logout successful.")
        else:
            print("Logout failure!")
            op.close()
            sys.exit(1)

    # select target data fram
    df = dfs[cfg["target_frame"]]

    # validate dataset
    if not set(cfg["expected_cols"]) == set(df.keys()):
        print("Error: data does not match expected format!")
        print("Expected: {}".format(set(cfg["expected_cols"])))
        print("Got: {}".format(set(df.keys())))
        sys.exit(1)

    # add timestap to data set
    df['date'] = [ datetime.now() for i in range(len(df)) ]

    # save to database
    print("Saving...")
    db = "test.sqlite"
    conn = sqlite3.connect(cfg["db_path"])
    df.to_sql(name=cfg["table_name"], con=conn, if_exists='append')
    conn.close()

    print("Finished.")

if __name__ == "__main__":
    main()
