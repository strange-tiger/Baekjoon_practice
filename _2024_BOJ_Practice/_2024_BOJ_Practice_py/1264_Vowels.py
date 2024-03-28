# 1264_Vowels.py

import sys

vowels = ['a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U']
s = ""
while True :
    s = sys.stdin.readline().rstrip()
    if s == '#' :
        break
    cnt = 0
    for i in s :
        if i in vowels :
            cnt += 1
    print(cnt)