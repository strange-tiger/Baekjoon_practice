import sys

N = int(sys.stdin.readline().rstrip())
A = list(map(int, sys.stdin.readline().rstrip().split()))
M = int(sys.stdin.readline().rstrip())
B = list(map(int, sys.stdin.readline().rstrip().split()))

end = max(max(A), max(B)) + 1

idxA = [[] for _ in range(end)]
for i in range(len(A)):
    idxA[A[i]].append(i)
for i in range(1, end):
    idxA[i].reverse()

idxB = [[] for _ in range(end)]
for i in range(len(B)):
    idxB[B[i]].append(i)
for i in range(1, end):
    idxB[i].reverse()

LLCS = list()
curA = 0
curB = 0

for i in range(end - 1, 0, -1):
    while len(idxA[i]) > 0 and idxA[i][-1] < curA:
        idxA[i].pop()
    for _ in range(min(len(idxA[i]), len(idxB[i]))):
        curA = idxA[i].pop()
        curB = idxB[i].pop()
        LLCS.append(i)

print(len(LLCS))
print(*LLCS)