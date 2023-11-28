#!/usr/bin/python3
for f in range(0, 90):
    if f % 10 > f / 10:
        if f != 89:
            print("{:02d}, ".format(f), end='')
        else:
            print("{:02d}".format(f))
