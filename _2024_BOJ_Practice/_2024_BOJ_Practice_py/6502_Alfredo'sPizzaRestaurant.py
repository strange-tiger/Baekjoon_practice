import sys

case = 1
while True:
    testcase = list(map(int, sys.stdin.readline().rstrip().split()))

    if testcase[0] == 0:
        break

    r, w, l = testcase

    d = w**2 + l**2
    if 4 * r**2 >= d:
        print(f"Pizza {case} fits on the table.")
    else:
        print(f"Pizza {case} does not fit on the table.")
    case += 1