import sys

N, M = map(int, sys.stdin.readline().rstrip().split())

A = list()
B = list()
for _ in range(N):
    A.append(list(map(int, list(sys.stdin.readline().rstrip()))))
for _ in range(N):
    B.append(list(map(int, list(sys.stdin.readline().rstrip()))))

def reverse(i, j):
    for y in range(i, i + 3):
        for x in range(j, j + 3):
            if A[y][x] == 1:
                A[y][x] = 0
            else:
                A[y][x] = 1

cnt = 0
if (N < 3 or M < 3) and A != B:
    cnt = -1
else:
    for n in range(N - 2):
        for m in range(M - 2):
            if A[n][m] != B[n][m]:
                cnt += 1
                reverse(n, m)
    if A != B:
        cnt = -1

print(cnt)