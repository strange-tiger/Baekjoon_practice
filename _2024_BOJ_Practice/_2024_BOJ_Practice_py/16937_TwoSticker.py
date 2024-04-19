import sys

H, W = map(int, sys.stdin.readline().rstrip().split())
N = int(sys.stdin.readline().rstrip())
stk = list(list(map(int, sys.stdin.readline().rstrip().split())) for _ in range(N))
result = 0

for i in range(N):
    for j in range(i + 1, N):
        r1, c1 = stk[i]
        r2, c2 = stk[j]

        if ((r1 + r2 <= H and max(c1, c2) <= W) or (max(r1, r2) <= H and c1 + c2 <= W)) or ((c1 + r2 <= H and max(r1, c2) <= W) or (max(c1, r2) <= H and r1 + c2 <= W)) or ((c1 + c2 <= H and max(r1, r2) <= W) or (max(c1, c2) <= H and r1 + r2 <= W)) or ((r1 + c2 <= H and max(c1, r2) <= W) or (max(r1, c2) <= H and c1 + r2 <= W)):
            result = max(result, r1 * c1 + r2 * c2)

print(result)