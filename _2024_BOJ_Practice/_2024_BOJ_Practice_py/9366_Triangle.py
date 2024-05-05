import sys

for case in range(int(sys.stdin.readline().rstrip())):
    side = sorted(map(int, sys.stdin.readline().rstrip().split()))

    print(f"Case #{case + 1}: ", end='')
    if side[2] >= side[0] + side[1]:
        print("invalid!")
    elif side[0] == side[1] == side[2]:
        print("equilateral")
    elif side[0] == side[1] or side[1] == side[2] or side[2] == side[0]:
        print("isosceles")
    else:
        print("scalene")