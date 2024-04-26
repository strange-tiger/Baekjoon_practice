import sys

N = int(sys.stdin.readline().rstrip())
trees = list(map(int, sys.stdin.readline().rstrip().split()))

trees.sort(reverse=True)

for i in range(N):
    trees[i] += i + 2

print(max(trees))