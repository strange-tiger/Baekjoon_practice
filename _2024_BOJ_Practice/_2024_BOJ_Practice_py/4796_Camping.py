# 4796_Camping.py

import sys

L, P, V = map(int, sys.stdin.readline().rstrip().split())
cnt = 0
while L + P + V > 0 :
    cnt += 1
    ans = 0
    ans += L * (V // P)
    if V % P > L :
        ans += L
    else :
        ans += V % P
    print("Case %d: %d" % (cnt, ans))
    L, P, V = map(int, sys.stdin.readline().rstrip().split())