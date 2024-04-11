import sys

B = sys.stdin.readline().rstrip()
B = B.replace("XXXX", "AAAA").replace("XX", "BB")

if 'X' in B:
    print(-1)
else:
    print(B)