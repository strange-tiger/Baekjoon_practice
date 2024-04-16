import sys

a = list(map(int, sys.stdin.readline().rstrip().split()))
b = list(map(int, sys.stdin.readline().rstrip().split()))

if a[2] < b[0] or b[2] < a[0] or a[1] > b[3] or a[3] < b[1]:
    print('NULL')
elif a[0] == b[2] or b[0] == a[2]:
    if a[3] == b[1] or b[3] == a[1]:
        print('POINT')
    else:
        print('LINE')
elif a[3] == b[1] or b[3] == a[1]:
    print('LINE')
else:
    print('FACE')