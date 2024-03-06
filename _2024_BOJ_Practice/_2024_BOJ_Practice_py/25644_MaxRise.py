import sys

N = int(sys.stdin.readline().rstrip())
a = list(map(int, sys.stdin.readline().rstrip().split()))

Max = max(a)
Min = Max if a.index(Max) == 0 else min(a[:a.index(Max)])
Min = Min if Min <= Max else Max
bene1 = Max - Min

Min = min(a)
Max = Min if a.index(Min) == N - 1 else max(a[a.index(Min):])
Max = Max if Max >= Min else Min
bene2 = Max - Min

print (max([bene1, bene2]))