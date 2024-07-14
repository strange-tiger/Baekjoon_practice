import sys
input = sys.stdin.readline

N = int(input())
M = int(input())
table = [[0] * N for _ in range(N)]
dx = [0, 1, 0, -1]
dy = [-1, 0, 1, 0]

x = y = N // 2
table[y][x] = 1

num = 2
repeat = 1
idx = 0

ans = [y + 1, x + 1]

while x != 0 or y != 0:
    flag = 0
    for _ in range(2):
        for _ in range(repeat):
            x += dx[idx]
            y += dy[idx]
            table[y][x] = num

            if num == M:
                ans = [y + 1, x + 1]

            if x == 0 and y == 0:
                flag = 1
                break
            num += 1

        if flag == 1:
            break

        idx = (idx + 1) % 4
    repeat += 1

for i in table:
    print(*i)

print(*ans)