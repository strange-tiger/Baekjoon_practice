import sys

num = list(map(int, sys.stdin.readline().rstrip().split()))
num.sort()
print(num[1])