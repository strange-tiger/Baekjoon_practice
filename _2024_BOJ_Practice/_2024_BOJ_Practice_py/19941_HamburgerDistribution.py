import sys

N, K = map(int, sys.stdin.readline().rstrip().split())
S = list(sys.stdin.readline().rstrip())

cnt = 0
for i in range(N):
    if S[i] == 'P':
        for j in range(max(i - K, 0), min(i + K + 1, N)):
            if S[j] == 'H':
                cnt += 1
                S[j] = 0
                break

print(cnt)