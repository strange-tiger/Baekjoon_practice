import sys

T = int(sys.stdin.readline().rstrip())

for _ in range(T):
    V, E = map(int, sys.stdin.readline().rstrip().split())
    print(2 + E - V)