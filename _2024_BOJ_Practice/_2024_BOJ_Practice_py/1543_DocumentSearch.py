# 1543_DocumentSearch.py

import sys

docu = sys.stdin.readline().rstrip()
word = sys.stdin.readline().rstrip()
D = len(docu)
L = len(word)
cnt = 0

i = 0
while i <= D - L :
    if docu[i:i + L] == word :
        cnt += 1
        i += L
    else :
        i += 1

print(cnt)