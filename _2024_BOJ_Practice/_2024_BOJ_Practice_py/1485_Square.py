import sys

def distance(a, b):
    return (b[0] - a[0])**2 + (b[1] - a[1])**2

T = int(sys.stdin.readline().rstrip())
for _ in range(T):
    v = [list(map(int, sys.stdin.readline().rstrip().split())) for _ in range(4)]

    square = list()
    for i in range(0, 3):
        for j in range(i + 1, 4):
            square.append(distance(v[i], v[j]))

    answer = 1
    square.sort()
    tmp = square[0]
    for i in range(1, 4):
        if tmp != square[i]:
            answer = 0
    if square[4] != square[5]:
        answer = 0

    print(answer)