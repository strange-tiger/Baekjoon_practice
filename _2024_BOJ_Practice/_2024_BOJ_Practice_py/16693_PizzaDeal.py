import sys
from math import pi

A1, P1 = map(int, sys.stdin.readline().rstrip().split())
R1, P2 = map(int, sys.stdin.readline().rstrip().split())

if P1 / A1 < P2 / (R1**2 * pi):
    print("Slice of pizza")
else:
    print("Whole pizza")