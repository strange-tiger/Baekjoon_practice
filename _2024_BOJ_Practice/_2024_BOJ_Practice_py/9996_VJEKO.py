import sys

N = int(sys.stdin.readline().rstrip())

begin, end = sys.stdin.readline().rstrip().split('*')
L = len(begin) + len(end)

for _ in range(N) :
    txt = sys.stdin.readline().rstrip()
    if len(txt) < L :
        print("NE")
    else :
        if txt[:len(begin)] == begin and txt[-len(end):] == end :
            print("DA")
        else :
            print("NE")