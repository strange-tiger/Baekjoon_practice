import sys

num = input()

if '0' not in num:
    print(-1)
elif int(num) % 3 != 0:
    print(-1)
else:
    sortedNum = sorted(num, reverse = True)
    print("".join(sortedNum))