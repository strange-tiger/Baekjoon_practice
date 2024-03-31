import sys

N = int(sys.stdin.readline().rstrip())

begin, end = sys.stdin.readline().rstrip().split('*')

for _ in range(N) :
    txt = sys.stdin.readline().rstrip()
    if txt[:len(begin)] == begin and txt[len(txt) - len(end):] == end :
        print("DA")
    else :
        print("NE")