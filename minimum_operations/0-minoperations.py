#!/usr/bin/python3
"""
Find minimum operations with copy - paste to have n numbers of characters.
"""


# use of primary numbers
def minOperations(n):
    # d = 2 => smallest primary number
    d = 2
    op = 0
    while d * d <= n:
        if n % d:
            d += 1
        else:
            n //= d
            op += d
    if n > 1:
        op += n
    return op
