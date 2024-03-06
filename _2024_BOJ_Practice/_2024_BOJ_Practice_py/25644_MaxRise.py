import sys

N = int(sys.stdin.readline().rstrip())
a = list(map(int, sys.stdin.readline().rstrip().split()))

Max = 0
benefit = 0

for i in range(N - 1, -1, -1) :
    Max = max(Max, a[i])
    benefit = max(benefit, Max - a[i])

print(benefit)