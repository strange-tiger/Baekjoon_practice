import sys

N = int(sys.stdin.readline().rstrip())
A = list(map(int, sys.stdin.readline().rstrip().split()))
sortA = sorted(A)

P = list()
for i in range(N):
    P.append(sortA.index(A[i]))
    sortA[P[-1]] = -1

for i in range(N):
    print(str(P[i]),end=' ')