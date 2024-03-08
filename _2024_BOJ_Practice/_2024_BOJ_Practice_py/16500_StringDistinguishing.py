import sys

S = sys.stdin.readline().rstrip()
N = int(sys.stdin.readline().rstrip())
A = []
dp = [0] * 101
for _ in range(N) :
    A.append(sys.stdin.readline().rstrip())

L = len(S)
dp[L] = 1


for i in range(L - 1, -1, -1) :
    for j in range(N) :
        if S.find(A[j]) == i and dp[i + len(A[j])] :
            dp[i] = 1
            break
        else :
            dp[i] = 0

print(dp[0])