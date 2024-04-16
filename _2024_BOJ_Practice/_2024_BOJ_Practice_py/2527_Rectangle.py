import sys

for _ in range(4):
    v = list(map(int, sys.stdin.readline().rstrip().split()))

    a = v[0:4]
    b = v[4:8]
    x = 0
    y = 1
    p = 2
    q = 3

    if a[p] < b[x] or b[p] < a[x] or a[y] > b[q] or a[q] < b[y]:
        print('d')
    elif a[x] == b[p] or b[x] == a[p]:
        if a[q] == b[y] or b[q] == a[y]:
            print('c')
        else:
            print('b')
    elif a[q] == b[y] or b[q] == a[y]:
        print('b')
    else:
        print('a')