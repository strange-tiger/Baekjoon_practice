# 12891_DNAPassword.py

import sys

S, P = map(int, sys.stdin.readline().rstrip().split())
DNA = sys.stdin.readline().rstrip()
num = list(map(int, sys.stdin.readline().rstrip().split()))
words = ['A', 'C', 'G', 'T']

cnt = 0
for i in range(S - P + 1) :
    able = True
    for j in range(4) :
        if num[j] > DNA[i : i + P].count(words[j]) :
            able = False
            break
    if able :
        cnt += 1

print(cnt)