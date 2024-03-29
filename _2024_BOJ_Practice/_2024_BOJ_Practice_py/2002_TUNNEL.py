# 2002_TUNNEL.py

import sys

N = int(sys.stdin.readline().rstrip())
before = list()
after = list()

for _ in range(N) :
    before.append(sys.stdin.readline().rstrip())
for _ in range(N) :
    after.append(sys.stdin.readline().rstrip())

cnt = 0
i = 0
while i < len(before) :
    if before[i] != after[i] :
        cnt += 1
        before.remove(after.pop(i))
    else :
        i += 1

print(cnt)