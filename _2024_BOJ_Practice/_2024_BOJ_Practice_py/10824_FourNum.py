# 10824_FourNum.py

import sys

num = sys.stdin.readline().rstrip().split()

AB = num[0] + num[1]
CD = num[2] + num[3]

print(int(AB) + int(CD))