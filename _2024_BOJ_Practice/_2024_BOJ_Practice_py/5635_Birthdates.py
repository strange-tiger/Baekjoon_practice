# 5635_Birthdates.py

import sys

N = int(sys.stdin.readline().rstrip())

dates = list()

for _ in range(N) :
    temp = sys.stdin.readline().rstrip().split()
    dates.append([temp[0], list(map(int, temp[1:]))])

Min = ["", [0, 0, 1989]]
Max = ["", [32, 13, 2011]]

for d in dates :
    if d[1][2] > Min[1][2] :
        Min = d
    elif d[1][2] == Min[1][2] :
        if d[1][1] > Min[1][1] :
            Min = d
        elif d[1][1] == Min[1][1] :
            if d[1][0] > Min[1][0] :
                Min = d

    if d[1][2] < Max[1][2] :
        Max = d
    elif d[1][2] == Max[1][2] :
        if d[1][1] < Max[1][1] :
            Max = d
        elif d[1][1] == Max[1][1] :
            if d[1][0] < Max[1][0]:
                Max = d

print(Min[0])
print(Max[0])