#!/usr/bin/env python3

# Copyright (c) 2021 tick <tickelton@gmail.com>
# SPDX-License-Identifier:	MIT

import sys
import importlib
import argparse
import http.cookiejar
import urllib.parse
import urllib.request
#import pandas

PROGNAME="scrape-o-mat"
VERSION="0.0.1"


def main():
    parser = argparse.ArgumentParser(prog=PROGNAME)
    parser.add_argument('--version', action='version', version='%(prog)s v' + VERSION)
    parser.add_argument('config_module', metavar='CONFIG', type=str, nargs=1,
                                help='configuration module name')
    args = parser.parse_args()

    cfg = importlib.import_module(args.config_module[0]).cfg

    print(cfg)

    cookie_jar = http.cookiejar.CookieJar()
    op = urllib.request.build_opener(urllib.request.HTTPCookieProcessor(cookie_jar))
    post_data = urllib.parse.urlencode(cfg.login.post_data)
    post_data = post_data.encode('ascii')
    op.addheaders = [('User-Agent', cfg.user_agent)]
    try:
        result = op.open(cfg.login.url, post_data)
        status = result.getcode()
        reason = result.msg
    except HTTPError as e:
        status = e.code
        reason = e.msg
    except OSError as e:
        print(str(e))
        raise

    if status == 200:
       res.read()
    else:
        print("foofail")
        raise DistutilsError(msg)

    res.close()


    # insert random delay to appear more human

    post_data = urllib.parse.urlencode(cfg.fetch.post_data)
    post_data = post_data.encode('ascii')
    res = op.open(cfg.fetch.url, post_data)
    res.getcode()
    res.read()
    foo = res.read()
    dfs = pandas.read_html(foo)

    # insert more random delay

    res = op.open(cfg.logout.url)
    res.getcode()
    res.read()



if __name__ == "__main__":
    main()
