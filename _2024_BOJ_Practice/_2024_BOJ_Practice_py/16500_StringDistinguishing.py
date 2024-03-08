import sys

S = sys.stdin.readline().rstrip()
N = int(sys.stdin.readline().rstrip())
A = []
dp = [0] * 101
for _ in range(N) :
    A.append(sys.stdin.readline().rstrip())
L = len(S)

def solution(idx):
    global result

    if idx == L :
        result = 1
        return
    if dp[idx] :
        return

    dp[idx] = 1

    for i in A :
        if L >= idx + len(i) :
            if S[idx : idx + len(i)] == i :
                solution(idx + len(i))

result = 0
solution(0)

print(result)