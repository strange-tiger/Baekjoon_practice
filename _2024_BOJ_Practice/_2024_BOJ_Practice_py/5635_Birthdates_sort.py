# 5635_Birthdates_sort.py

import sys

N = int(sys.stdin.readline().rstrip())

dates = list()

for _ in range(N) :
    temp = sys.stdin.readline().rstrip().split()
    dates.append([temp[0], list(map(int, temp[1:]))])

dates.sort(key = lambda x: (x[1][2], x[1][1], x[1][0]))

print(dates[-1][0])
print(dates[0][0])