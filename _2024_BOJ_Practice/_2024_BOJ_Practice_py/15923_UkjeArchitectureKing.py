import sys

X, Y = list(), list()

for _ in range(int(sys.stdin.readline().rstrip())):
    x, y = map(int, sys.stdin.readline().rstrip().split())

    X.append(x)
    Y.append(y)

print((max(X) - min(X) + max(Y) - min(Y)) * 2)