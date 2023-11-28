#!/usr/bin/python3
def fizzbuzz():
    for unit in range(1, 101):
        if (unit % 3 == 0 and unit % 5 == 0):
            print("FizzBuzz", end=" ")
        elif (unit % 3 == 0):
            print("Fizz", end=" ")
        elif (unit % 5 == 0):
            print("Buzz", end=" ")
        else:
            print("{}".format(unit), end=" ")
