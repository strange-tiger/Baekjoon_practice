import sys
import heapq

N, K = map(int, sys.stdin.readline().rstrip().split())

jewels = list()
for _ in range(N):
    heapq.heappush(jewels, list(map(int, sys.stdin.readline().rstrip().split())))

bags = [int(sys.stdin.readline().rstrip()) for _ in range(K)]
bags.sort()

answer = 0
able = list()
for bag in bags:
    while jewels and bag >= jewels[0][0]:
        heapq.heappush(able, -heapq.heappop(jewels)[1])
    if able:
        answer -= heapq.heappop(able)
    elif not jewels:
        break

print(answer)