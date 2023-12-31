#!/usr/bin/python3

"""
Module 0-stats
Exercice Log parsing
"""

import sys
import traceback
import re


def main():
    """
    main
    """
    size = 0
    counter = 0
    status_map = {}
    pattern = re.compile("[0-9][0-9][0-9]")
    line_parsed2 = []
    try:
        for line in sys.stdin:
            """ jose """
            if "-[" in line:
                line = line.replace("-[", " - [")
            line_parsed = line.split()
            if len(line_parsed) >= 8:
                if pattern.match(line_parsed[7]):
                    key = line_parsed[7]
                    status_map[key] = status_map.get(key, 0) + 1
                if len(line_parsed) >= 9:
                    size += int(line_parsed[8])
            counter += 1
            if counter % 10 == 0:
                print_result(size, status_map)
    except KeyboardInterrupt:
        """ Keyboard interruption """
        traceback.print_exc()  # Print the traceback when interrupted
        sys.exit(1)  # Exit with a non-zero status code
    finally:
        """ """
        # Print the final statistics
        print_result(size, status_map)


def print_result(size, status_map):
    """ print_result """
    print("File size: {}".format(size))
    for key, value in sorted(status_map.items()):
        print("{}: {}".format(key, value))

if __name__ == "__main__":
    main()
