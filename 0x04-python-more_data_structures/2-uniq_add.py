#!/usr/bin/python3


def uniq_add(my_list=[]):
    out_put = 0
    for i in set(my_list):
        out_put += i
    return out_put
