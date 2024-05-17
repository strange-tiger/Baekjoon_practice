import sys

w, h = map(int, sys.stdin.readline().rstrip().split())
answer = w + h - (w**2 + h**2)**0.5

print(answer)