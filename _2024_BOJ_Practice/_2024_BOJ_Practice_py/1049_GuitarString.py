import sys

N, M = map(int, input().split())

answer = 0
sixList = []
oneList = []

for _ in range(M):
    six, one = map(int, input().split())
    sixList.append(six)
    oneList.append(one)

six = min(sixList)
one = min(oneList)

sixNum = N // 6
oneNum = N % 6

answer = min([six * (sixNum + 1), six * sixNum + one * oneNum, one * N])

print(answer)