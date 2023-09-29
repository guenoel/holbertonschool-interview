#!/usr/bin/python3

"""
Module 0-stats
Exercice Log parsing
"""

import sys


def main():
    """
    main
    """
    size = 0
    counter = 0
    status_map = {}
    for line in sys.stdin:
        """ jose """
        line_parsed = line.split(" ")
        if len(line_parsed) >= 8:
            key = line_parsed[7]
            status_map[key] = status_map.get(key, 0) + 1
        counter += 1
        if len(line_parsed) >= 9:
            size += int(line_parsed[8])
        if counter > 10:
            print("File size: {}".format(size))
            for key, value in status_map.items():
                print("{}: {}".format(key, value))


if __name__ == "__main__":
    main()
