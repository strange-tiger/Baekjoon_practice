import sys

N = int(sys.stdin.readline().rstrip())

d = {}
for _ in range(N) :
    key = sys.stdin.readline().rstrip()
    if key in d :
        d[key] += 1
    else :
        d[key] = 1

l = sorted(sorted(d.items()), key=lambda x : x[1], reverse=True)
print(l[0][0])