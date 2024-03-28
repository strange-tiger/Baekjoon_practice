# 11655_ROT13.py

import sys

SA = 97
SZ = 122
BA = 65
BZ = 90
RANGE = 26

origin = sys.stdin.readline().rstrip()
cipher = ""

for i in origin :
    if (i >= 'a' and i <= 'z') or (i >= 'A' and i <= 'Z') :
        c = ord(i) + 13
        if (c > SZ) or (c > BZ and i <= 'Z') :
            c -= RANGE
        i = chr(c)
    cipher += i

print(cipher)