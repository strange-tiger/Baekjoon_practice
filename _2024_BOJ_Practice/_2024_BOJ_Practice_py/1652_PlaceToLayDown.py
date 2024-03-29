# 1652_PlaceToLayDown.py

import sys

N = int(sys.stdin.readline().rstrip())
place = list()
for _ in range(N) :
    place.append(sys.stdin.readline().rstrip())

x, y = 0, 0
for i in range(N) :
    leng_x, leng_y = 0, 0
    for j in range(N) :
        if place[i][j] == '.' :
            leng_x += 1
        else :
            leng_x = 0
        if leng_x == 2 :
            x += 1
    for j in range(N) :
        if place[j][i] == '.' :
            leng_y += 1
        else :
            leng_y = 0
        if leng_y == 2 :
            y += 1

print("%d %d" % (x, y))