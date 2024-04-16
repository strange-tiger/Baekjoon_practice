import sys

def distance(a, b):
    return abs(a[0] - b[0]) + abs(a[1] - b[1])

N = int(sys.stdin.readline().rstrip())

points = list()
for _ in range(N):
    points.append(list(map(int, sys.stdin.readline().rstrip().split())))

sum = 0
dist = list()
for i in range(N - 1):
    dist.append(distance(points[i], points[i + 1]))
    sum += dist[i]

result = 2000000000
for i in range(1, N - 1):
    skip = sum - dist[i - 1] - dist[i] + distance(points[i - 1], points[i + 1])
    if result > skip:
        result = skip

print(result)