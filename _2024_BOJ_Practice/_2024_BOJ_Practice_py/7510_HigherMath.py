import sys

n = int(sys.stdin.readline().rstrip())

for i in range(1, n + 1):
    a, b, c = map(int, sys.stdin.readline().rstrip().split())
    print("Scenario #%d:" % i)
    if a**2 == b**2 + c**2 or b**2 == c**2 + a**2 or c**2 == a**2 + b**2:
        print("yes\n")
    else:
        print("no\n")