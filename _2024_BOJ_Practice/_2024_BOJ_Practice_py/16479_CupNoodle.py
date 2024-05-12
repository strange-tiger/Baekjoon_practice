import sys

K = int(sys.stdin.readline().rstrip())
D1, D2 = map(int, sys.stdin.readline().rstrip().split())

print(round(K**2 - ((D1 - D2) / 2)**2, 6))