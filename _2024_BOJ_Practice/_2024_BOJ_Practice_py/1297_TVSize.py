import sys

D, H, W = map(int, sys.stdin.readline().rstrip().split())

r = D / (H**2 + W**2)**0.5
print(int(H * r), int(W * r))