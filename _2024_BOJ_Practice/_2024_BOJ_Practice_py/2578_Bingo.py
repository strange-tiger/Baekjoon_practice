import sys

input = sys.stdin.readline

board = list()
for _ in range(5):
    board.append(list(map(int, input().rstrip().split())))

mc = list()
for _ in range(5):
    mc.append(list(map(int, input().rstrip().split())))

bingo = [[False] * 5 for _ in range(5)]

def checkX():
    bingoX= 0
    for i in range(5):
        cnt = 0
        for j in range(5):
            if bingo[i][j]:
                cnt += 1

        if cnt == 5:
            bingoX += 1
    return bingoX

def checkY():
    bingoY = 0
    for i in range(5):
        cnt = 0
        for j in range(5):
            if bingo[j][i]:
                cnt += 1

        if cnt == 5:
            bingoY += 1
    return bingoY

def checkDia():
    bingoDia = 0
    cnt = 0
    for i in range(5):
        if bingo[i][i]:
            cnt += 1
    if cnt == 5:
        bingoDia += 1

    cnt = 0
    for i in range(5):
        if bingo[i][4 - i]:
            cnt += 1
    if cnt == 5:
        bingoDia += 1
    return bingoDia

def solve():
    for i in range(5):
        for j in range(5):
            m = mc[i][j]
            for y in range(5):
                for x in range(5):
                    if board[y][x] == m:
                        cnt = 0
                        bingo[y][x] = True
                        cnt = checkX() + checkY() + checkDia()

                        if cnt > 2:
                            print(i * 5 + j + 1)
                            return

solve()