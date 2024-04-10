import sys

A, B = sys.stdin.readline().rstrip().split()

print(int(A.replace('6', '5')) + int(B.replace('6', '5')), int(A.replace('5', '6')) + int(B.replace('5', '6')))