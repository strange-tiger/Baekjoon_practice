import sys
from itertools import combinations

N = int(sys.stdin.readline().rstrip())
A = list(map(int, sys.stdin.readline().rstrip().split()))
M = int(sys.stdin.readline().rstrip())
B = list(map(int, sys.stdin.readline().rstrip().split()))

subseq = list(set(A) & set(B))

LLCS = [subseq[-1]]
for i in range(2, len(subseq) + 1):
    if subseq[-i] in A[A.index(LLCS[-1]):] and subseq[-i] in B[B.index(LLCS[-1]):]:
        LLCS.append(subseq[-i])

print(len(LLCS))
print(*LLCS)