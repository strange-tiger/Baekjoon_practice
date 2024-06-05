import sys

N = int(sys.stdin.readline().rstrip())
A = list(map(int, sys.stdin.readline().rstrip().split()))
M = int(sys.stdin.readline().rstrip())
B = list(map(int, sys.stdin.readline().rstrip().split()))

intersec = list(set(A) & set(B))

LLCS = [intersec[-1]]
idxA = A.index(LLCS[-1])
idxB = B.index(LLCS[-1])
while len(intersec) > 0:
    if idxA == len(A) - 1 or idxB == len(B) - 1:
        break
    if intersec[-1] in A[idxA + 1:] and intersec[-1] in B[idxB + 1:]:
        LLCS.append(intersec[-1])
        idxA += A[idxA + 1:].index(LLCS[-1]) + 1
        idxB += B[idxB + 1:].index(LLCS[-1]) + 1
    else:
        intersec.remove(intersec[-1])

print(len(LLCS))
print(*LLCS)