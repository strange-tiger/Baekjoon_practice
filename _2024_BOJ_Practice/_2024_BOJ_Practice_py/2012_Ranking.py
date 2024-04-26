import sys

N = int(sys.stdin.readline().rstrip())

rank = list()
for _ in range(N):
    rank.append(int(sys.stdin.readline().rstrip()))

rank.sort()

ans = 0
for i in range(N):
    ans += abs(i - rank[i] + 1)

print(ans)