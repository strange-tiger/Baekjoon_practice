# 2902_AUTORI.py

import sys

long = sys.stdin.readline().rstrip().split('-')
ans = ""

for i in long :
    ans += i[0]

print(ans)