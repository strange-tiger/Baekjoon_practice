import sys

N = int(sys.stdin.readline().rstrip())

rank = list()
for _ in range(N):
    rank.append(int(sys.stdin.readline().rstrip()))

rank.sort()

ansA = 0
for i in range(N):
    ansA += abs(i - rank[i] + 1)

ansB = 0
rankB = list()
for i in range(N):
    if rank[i] != i + 1:
        rankB.append(rank[i])

for i in range(len(rankB)):
    ansB += i + 1 + len(rank) - len(rankB) - rankB[i]

print(min(ansA, ansB))