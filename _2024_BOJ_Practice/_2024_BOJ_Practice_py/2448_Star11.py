import sys

N = int(input())

star = [[' '] * 2 * N for _ in range(N)]

def triangle(row, col, size) :
    if size == 3 :
        star[row][col] = '*'
        star[row + 1][col - 1] = '*'
        star[row + 1][col + 1] = '*'
        
        for i in range(-2, 3) :
            star[row + 2][col + i] = '*'
    else :
        half = size // 2
        
        triangle(row, col, half)
        triangle(row + half, col - half, half)
        triangle(row + half, col + half, half)

triangle(0, N - 1, N)

for s in star :
    print("".join(s))