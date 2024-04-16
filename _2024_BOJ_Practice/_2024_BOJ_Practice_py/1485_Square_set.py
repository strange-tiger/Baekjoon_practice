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

    # answer = 1
    # square.sort()
    # tmp = square[0]
    # for i in range(1, 4):
    #     if tmp != square[i]:
    #         answer = 0
    # if square[4] != square[5]:
    #     answer = 0

    # print(answer)

# 정사각형의 조건은 두 대각선의 길이가 같고, 모든 변의 길이가 같은 것이다.

    if len(set(square)) == 2 and square.count(max(square)) == 2 and square.count(min(square)) == 4:
        print(1)
    else:
        print(0)

# 재미있는 방법이 있어 추가로 올린다.
# set을 사용해 square의 고유 원소를 셀 수 있다.
# 정사각형은 대각선이 2개 같고 변이 4개 같으니 고유 원소는 2개이다.
# max, min으로 정사각형의 대각선 개수, 변 개수를 셀 수 있다.
# https://velog.io/@xenrose/Python-%EB%B0%B1%EC%A4%80-1485%EB%B2%88-%EC%A0%95%EC%82%AC%EA%B0%81%ED%98%95