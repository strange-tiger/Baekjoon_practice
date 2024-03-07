import sys

s = sys.stdin.readline().rstrip()
exp = sys.stdin.readline().rstrip()

while s.find(exp) != -1 :
    s = s.replace(exp, '')

if s == "" :
    print("FRULA")
else :
    print(s)