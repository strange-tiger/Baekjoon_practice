import sys

S = sys.stdin.readline().rstrip()

suffix = []

for i in range(len(S)) :
    suffix.append(S[i:])

suffix.sort()

for s in suffix :
    print(s)