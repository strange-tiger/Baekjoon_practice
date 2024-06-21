import sys

N = sys.stdin.readline().rstrip()
num = [0] * 10

for i in range(len(N)):
    if N[i] == '6' or N[i] == '9':
        if num[6] < num[9]:
            num[6] += 1
        else:
            num[9] += 1
    else:
        num[int(N[i])] += 1

print(max(num))