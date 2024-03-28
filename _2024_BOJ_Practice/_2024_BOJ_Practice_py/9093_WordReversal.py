import sys

T = int(sys.stdin.readline().rstrip())

for _ in range(T) :
    S = sys.stdin.readline().rstrip().split()
    answer = ""
    for s in S :
        r = list(s)
        r.reverse()
        s = ''.join(r)
        answer += s
        answer += ' '
    print(answer)

# reverse()
# https://blockdmask.tistory.com/581