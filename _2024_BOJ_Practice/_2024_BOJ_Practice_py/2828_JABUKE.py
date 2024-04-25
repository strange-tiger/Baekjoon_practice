import sys

N, M = map(int, sys.stdin.readline().rstrip().split())
J = int(sys.stdin.readline().rstrip())
apples = list()
answer = 0

now = 1
for _ in range(J):
    apples.append(int(sys.stdin.readline().rstrip()))

for a in apples:
    if now > a:
        answer += now - a
        now = a
    elif now + M - 1 < a:
        answer += a - M + 1 - now
        now = a - M + 1

print(answer)