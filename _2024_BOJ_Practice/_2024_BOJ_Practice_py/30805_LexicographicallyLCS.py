import sys

N = int(sys.stdin.readline().rstrip())
A = list(map(int, sys.stdin.readline().rstrip().split()))
M = int(sys.stdin.readline().rstrip())
B = list(map(int, sys.stdin.readline().rstrip().split()))

intersec = list(set(A) & set(B))
intersec.sort(reverse=True)

LLCS = list()
idxA = idxB = 0

for i in intersec:
    for j in range(idxA, len(A)):
        if i == A[j] and j >= idxA:
            for k in range(idxB, len(B)):
                if i == B[k] and k >= idxB:
                    idxA = j + 1
                    idxB = k + 1
                    LLCS.append(i)
                    break

print(len(LLCS))
print(*LLCS)