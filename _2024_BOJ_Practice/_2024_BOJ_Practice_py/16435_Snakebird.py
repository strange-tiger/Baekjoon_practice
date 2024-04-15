import sys

N, L = map(int, sys.stdin.readline().rstrip().split())

H = list(map(int, sys.stdin.readline().rstrip().split()))

notLimit = True
while notLimit:
    notLimit = False
    for i in H:
        if i <= L:
            L += 1
            H.remove(i)
            notLimit = True

print(L)