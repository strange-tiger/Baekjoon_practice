import sys

N = int(sys.stdin.readline().rstrip())
words = [sys.stdin.readline().rstrip() for _ in range(N)]
letters = dict()

for i in words:
    x = len(i) - 1

    for j in i:
        if j in letters:
            letters[j] += 10**x
        else:
            letters[j] = 10**x
        x -= 1

values = sorted(letters.values(), reverse=True)

answer = 0
num = 9
for i in values:
    answer += i * num
    num -= 1

print(answer)