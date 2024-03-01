import sys

num = input()

cnt = [0, 0]
now = num[0]
for i in num:
    if i != now :
        cnt[int(now)] += 1
        now = i

if cnt[0] != 0 or cnt[1] != 0 :
    cnt[int(now)] += 1

print(min(cnt))