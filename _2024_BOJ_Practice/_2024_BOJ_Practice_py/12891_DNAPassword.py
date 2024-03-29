# 12891_DNAPassword.py

import sys

S, P = map(int, sys.stdin.readline().rstrip().split())
DNA = sys.stdin.readline().rstrip()
num = list(map(int, sys.stdin.readline().rstrip().split()))
words = ['A', 'C', 'G', 'T']

cnt = 0
check = [0] * 4
for i in range(0, S - P + 1) :
    able = True

    if i == 0 :
        for j in range(4) :
            check[j] = DNA[:P].count(words[j])
    else :
        check[words.index(DNA[i - 1])] -= 1
        check[words.index(DNA[i + P - 1])] += 1

    for j in range(4) :
        if num[j] > check[j] :
            able = False
            break
    if able :
        cnt += 1

print(cnt)