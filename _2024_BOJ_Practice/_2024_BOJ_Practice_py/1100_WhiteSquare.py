import sys

board = [""]*8
answer = 0

for i in range(8) :
    board[i] = sys.stdin.readline().rstrip()

for i in range(8) :
    for j in range(8) :
        if board[i][j] == 'F' and (i + j) % 2 == 0 :
            answer += 1

print(answer)