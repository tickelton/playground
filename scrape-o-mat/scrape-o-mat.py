#!/usr/bin/env python3

# Copyright (c) 2021 tick <tickelton@gmail.com>
# SPDX-License-Identifier:	MIT

import sys
import importlib
import argparse

PROGNAME="scrape-o-mat"
VERSION="0.0.1"


def main():
    parser = argparse.ArgumentParser(prog=PROGNAME)
    parser.add_argument('--version', action='version', version='%(prog)s v' + VERSION)
    parser.add_argument('config_module', metavar='CONFIG', type=str, nargs=1,
                                help='configuration module name')
    args = parser.parse_args()

    cfg = importlib.import_module(args.config_module[0])

    print(cfg.c)

if __name__ == "__main__":
    main()
