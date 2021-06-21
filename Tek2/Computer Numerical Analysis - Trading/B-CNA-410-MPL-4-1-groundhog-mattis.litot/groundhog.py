#!/usr/bin/env python3
import sys
import math
from decimal import localcontext, Decimal, ROUND_HALF_UP

a = 0
prevr = -1
switch = 0
mean = []
std = []

def documentation():
    print("SYNOPSIS\n    ./groundhog period\n\nDESCRIPTION    period        the number of days defining a period")

def calc(arr, size):
    global prevr
    global switch
    g = -1
    r = -1
    prevres = -1
    s = -1
    if (len(arr) >= size):
        global a
        window = arr[a : a + size]
        int1 = 0
        int2 = 0
        for x in window:
            int1 += x
            int2 += pow(x, 2)
        s = math.sqrt(abs(int2/size - (int1/size)*(int1/size)))
        if (len(arr) > size):
            g = 0
            if (arr[len(arr) - (size + 1)] != 0):
                r = ((arr[len(arr) - 1] - arr[len(arr) - (size + 1)]) / abs(arr[len(arr) - (size + 1)])) * 100
            elif (prevr >= 0):
                r = math.inf
            elif (prevr < 0):
                r = -math.inf
            window2 = arr[a : a + size]
            prev = arr[len(arr) - (size + 1)]
            for x in window2:
                if x - prev > 0:
                    g += x - prev
                prev = x
            g /= size
        a += 1
    mean.append(g)
    std.append(s)
    print("g=", end= '')
    if g == -1:
        print("nan", end= '')
    else:
        print(str("%.2f" % round(g, 2)), end= '')

    print("      r=", end= '')
    if r == -1:
        print("nan%", end= '')
    else:
        if r == math.inf or r == -math.inf:
            print(str(r) + "%", end= '')
        else:
            with localcontext() as ctx:
                ctx.rounding = ROUND_HALF_UP
                tmp = Decimal(r)
                print(str(tmp.to_integral_value()) + "%", end= '')
    print("      s=", end= '')
    if s == -1:
        print("nan", end="")
    else:
        print(str("%.2f" % round(s, 2)), end="")
    if (prevr > 0 and r < 0 and prevr != -1) or (prevr < 0 and r > 0 and prevr != -1):
        switch += 1
        print("      a switch occurs")
    else:
        print("\n", end="")
    prevr = r

def readFile(size):
    global switch
    arr = []
    weird = []
    sizeTmp = 0;
    while 1:
        try :
            x = input()
            if x == EOFError :
                exit(0)
            if (x == ""):
                continue
            if (x == "STOP"):
                if (sizeTmp < size):
                    exit(84)
                for i in range(len(arr)):
                    res = 0;
                    if (i == 0):
                        res = 0
                    elif (i == len(arr) - 1):
                        res = 0
                    else:
                        res = 2 * arr[i] - arr[i - 1] - arr[i + 1]
                    weird.append(tuple((abs(res), arr[i])))
                # print(weird)
                weird.sort(reverse=True)
                # print(weird)
                print("Global tendency switched " + str(switch) + " times")
                print("5 weirdest values are [", end= '')
                for i in range(4):
                    print(str(weird[i][1]) + ", ", end='')
                print(str(weird[4][1]) + "]")
                exit(0)
            arr.append(float(x))
            calc(arr, size)
            sizeTmp += 1
        except EOFError as e:
            exit(84)
        except ValueError:
            exit(84)

def main():
    if len(sys.argv) == 2:
        if sys.argv[1] == "-h":
            documentation()
            exit (0)
        else:
            readFile(int(sys.argv[1]))
    else:
        print("Invalid number of argument", file=sys.stderr)
        exit (84)

main()