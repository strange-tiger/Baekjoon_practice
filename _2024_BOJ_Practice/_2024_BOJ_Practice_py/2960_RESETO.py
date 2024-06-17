import sys

N, K = map(int, sys.stdin.readline().rstrip().split())

prime = [0] * (N + 1)
cnt = 0

for i in range(N + 1):
    prime[i] = i

for i in range(2, N + 1):
    for j in range(i, N + 1, i):
        if prime[j] != 0:
            prime[j] = 0
            cnt += 1
            if cnt == K:
                print(j)