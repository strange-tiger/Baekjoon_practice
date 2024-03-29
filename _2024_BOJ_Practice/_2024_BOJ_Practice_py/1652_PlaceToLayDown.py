# 1652_PlaceToLayDown.py

import sys

N = int(sys.stdin.readline().rstrip())
place = list()
for _ in range(N) :
    place.append(sys.stdin.readline().rstrip())

x, y = 0, 0

for i in range(N) :
    if place[i].find("..") != -1 :
        x += 1

place_y = list()
for i in range(N) :
    temp = ""
    for j in range(N) :
        temp += place[j][i]
    place_y.append(temp)

for i in range(N) :
    if place_y[i].find("..") != -1 :
        y += 1

print("%d %d" % (x, y))