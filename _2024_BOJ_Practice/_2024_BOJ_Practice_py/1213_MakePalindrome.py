# 1213_MakePalindrome.py

import sys

A = 65
a = [0]*26
name = sys.stdin.readline().rstrip()

for i in name :
    a[ord(i) - A] += 1

odd = 0
answer = ''
for i in range(26) :
    if a[i] % 2 == 1 :
        odd += 1
        a[i] -= 1
        answer = chr(i + A)

if odd > 1:
    print("I'm Sorry Hansoo")
else :
    for i in range(25, -1, -1) :
        for _ in range(a[i] // 2) :
            answer = answer + chr(i + A)
            answer = chr(i + A) + answer
    print(answer)