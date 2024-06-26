import sys

area = [[0] * 100 for _ in range(101)]

for _ in range(4):
    x1, y1, x2, y2 = map(int, sys.stdin.readline().rstrip().split())

    for i in range(y1, y2):
        for j in range(x1, x2):
            area[i][j] = 1

ans = 0
for i in area:
    for j in i:
        ans += j

print(ans)