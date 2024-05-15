import sys
from math import pi

s = int(sys.stdin.readline().rstrip())
answer = (s / pi)**0.5 * 2 * pi
print(answer)