import sys
input = sys.stdin.readline

able = list()

for i in range(1, 10):
    for j in range(1, 10):
        for k in range(1, 10):
            if (i != j and j != k and k != i):
                able.append(str(i) + str(j) + str(k))

N = int(input())

for _ in range(N):
    ask, s, b = input().split()
    s = int(s)
    b = int(b)

    idx = 0
    while(len(able) > idx):
        strike = ball = 0

        for j in range(3):
            if able[idx][j] == ask[j]:
                strike += 1
            elif ask[j] in able[idx]:
                ball += 1

        if strike != s or ball != b:
            able.remove(able[idx])
        else:
            idx += 1

print(len(able))