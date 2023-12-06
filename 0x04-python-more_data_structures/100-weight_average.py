
#!/usr/bin/python3


def weight_average(my_list=[]):
    """Return the weighted average of all integers in a list of tuples."""
    if not isinstance(my_list, list) or len(my_list) == 0:
        return (0)

    mean = 0
    cap = 0
    for tup in my_list:
        mean += (tup[0] * tup[1])
        cap += tup[1]
    return (mean / cap)
