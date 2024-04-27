import sys

N = int(sys.stdin.readline().rstrip())
seats = sys.stdin.readline().rstrip()

count = seats.count('LL')

if count < 2:
    print(len(seats))
else:
    print(len(seats) - count + 1)