import sys

input = sys.stdin.readline
N = int(input())

number = ['1', '2', '3', '4', '5', '6', '7', '8', '9']
base = list()

for i in number:
    for j in number:
        for k in number:
            if i != j and j != k and k != i:
                base.append(i + j + k)

for _ in range(N):
    ask, s, b = map(int, input().split())
    ask = str(ask)
    removeCnt = 0
    for i in range(len(base)):
        cntS, cntB = 0, 0
        i -= removeCnt
        for j in range(3):
            if base[i][j] == ask[j]:
                cntS += 1
            if ask[j] in base[i]:
                cntB += 1
        if s != cntS or b != cntB:
            base.remove(base[i])
            removeCnt += 1

print(len(base))