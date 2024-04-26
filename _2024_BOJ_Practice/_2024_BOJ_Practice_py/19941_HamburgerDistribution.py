import sys

N, K = map(int, sys.stdin.readline().rstrip().split())
S = list(sys.stdin.readline().rstrip())

cnt = 0
for i in range(N):
    if S[i] == 'H':
        if (i < N - K and 'P' in S[i:i + K + 1]) or (i >= K and 'P' in S[i - K:i]):
            cnt += 1
            S[i] = '0'

print(cnt)