import sys

N, K = map(int, sys.stdin.readline().rstrip().split())
answer = 0

jewels = list()
for _ in range(N):
    jewels.append(list(map(int, sys.stdin.readline().rstrip().split())))
jewels.sort(key=lambda j : j[1], reverse=True)

bags = list()
for _ in range(K):
    bags.append(int(sys.stdin.readline().rstrip()))
bags.sort()

for i in jewels:
    for j in range(K):
        if bags[j] >= i[0]:
            bags[j] = 0
            answer += i[1]
            break

print(answer)