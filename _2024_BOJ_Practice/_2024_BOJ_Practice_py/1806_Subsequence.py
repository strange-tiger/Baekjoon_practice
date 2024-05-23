import sys

N, S = map(int, sys.stdin.readline().rstrip().split())
seq = list(map(int, sys.stdin.readline().rstrip().split()))

front, back = 0, 0
Sum = seq[0]
len = N + 1

while True:
    if Sum >= S:
        len = min(len, back - front + 1)
        Sum -= seq[front]
        front += 1
    else:
        back += 1
        if back == N:
            break
        Sum += seq[back]

if len == N + 1:
    len = 0
print(len)