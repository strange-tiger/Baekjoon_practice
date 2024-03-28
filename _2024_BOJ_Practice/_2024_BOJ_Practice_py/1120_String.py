# 1120_String.py

import sys

a, b = sys.stdin.readline().rstrip().split()
diff = list()

for i in range(len(b) - len(a) + 1):
    cnt = 0
    for j in range(len(a)):
        if a[j] != b[i + j]:
            cnt += 1
    diff.append(cnt)

print(min(diff))