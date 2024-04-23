import sys

L, R = sys.stdin.readline().rstrip().split()

cnt = 0

if len(L) == len(R):
    for i in range(len(L)):
        if L[i] == R[i]:
            if L[i] == '8':
                cnt += 1
        else:
            break

print(cnt)