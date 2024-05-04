import sys

cnt = 1
while True:
    a, b, c = map(int, sys.stdin.readline().rstrip().split())
    if a == b == c == 0:
        break

    print(f"Triangle #{cnt}")
    if c == -1:
        print("c = %.3f\n" % ((a**2 + b**2)**0.5))
    elif max(a, b) >= c:
        print("Impossible.\n")
    elif a == -1:
        print("a = %.3f\n" % ((c**2 - b**2)**0.5))
    elif b == -1:
        print("b = %.3f\n" % ((c**2 - a**2)**0.5))
    cnt += 1