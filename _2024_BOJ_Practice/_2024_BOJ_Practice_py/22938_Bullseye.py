import sys

x1, y1, r1 = map(int, sys.stdin.readline().rstrip().split())
x2, y2, r2 = map(int, sys.stdin.readline().rstrip().split())
print('YES' if (r1 + r2)**2 > (x1 - x2)**2 + (y1 - y2)**2 else 'NO')