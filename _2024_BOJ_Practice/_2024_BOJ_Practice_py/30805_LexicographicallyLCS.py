import sys
from itertools import combinations

N = int(sys.stdin.readline().rstrip())
A = list(map(int, sys.stdin.readline().rstrip().split()))
M = int(sys.stdin.readline().rstrip())
B = list(map(int, sys.stdin.readline().rstrip().split()))

dp = [[0 for j in range(len(B))] for i in range(len(A))]
LCS = list()

for i in range(0, len(A)):
    for j in range(0, len(B)):
        if A[i] == B[j]:
            dp[i][j] = dp[i - 1][j - 1] + 1
            LCS.append(A[i])
        else:
            dp[i][j] = max(dp[i - 1][j], dp[i][j - 1])

subseq = list()
for i in range(len(LCS) + 1):
    subseq += list(combinations(LCS, i))
subseq.sort()

print(*subseq[len(subseq) - 1])