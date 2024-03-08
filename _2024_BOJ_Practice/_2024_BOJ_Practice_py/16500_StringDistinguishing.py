import sys

S = sys.stdin.readline().rstrip()
N = int(sys.stdin.readline().rstrip())
A = []
Ain = []
for i in range(N) :
    A.append(sys.stdin.readline().rstrip())

def Check (Str, cnt) :
    if cnt == 0 :
        return
    for i in A :
        if S == Str + i :
            print(1)
            exit()
        elif S.find(Str + i) != -1 :
            Str = Str + i
            Check(Str, cnt - 1)

Check("", len(S))
print(0)