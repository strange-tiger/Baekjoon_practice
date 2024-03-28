import sys

T = int(sys.stdin.readline().rstrip())

for _ in range(T) :
    A, B = map(int, input().split(','))
    print(A + B)