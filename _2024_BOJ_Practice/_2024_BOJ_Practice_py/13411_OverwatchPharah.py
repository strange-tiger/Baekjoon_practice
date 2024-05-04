import sys

N = int(sys.stdin.readline().rstrip())

time = list()

for i in range(1, N + 1):
    x, y, v = map(int, sys.stdin.readline().rstrip().split())
    dist = (x**2 + y**2)**0.5
    time.append((dist / v, i))

time.sort(key=lambda t: (t[0], t[1]))
for i in time:
    print(i[1])