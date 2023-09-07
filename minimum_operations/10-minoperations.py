#!/usr/bin/python3
"""
Find minimum operations with copy - paste to have n numbers of characters.
"""

def minOperations(n):
    if (n < 0):
        return (0)
    op = 0
    test = n
    i = n - 1
    while i > 0:
        if n % i == 0:
            op+=1
            print('copy i: {} n = {}'.format(i, n))
            while n > i:
                print('remove i: {} to {}'.format(i, n))
                n = n - i
                op+=1
            print('after loop i: {} n = {}'.format(i, n))
            if n == i:
                i -= 1
        print('i in big loop: {}'.format(i))
        i -= 1
    return op
        

