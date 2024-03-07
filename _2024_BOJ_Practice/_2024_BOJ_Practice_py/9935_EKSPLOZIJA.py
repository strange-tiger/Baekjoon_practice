import sys

s = sys.stdin.readline().rstrip()
exp = list(sys.stdin.readline().rstrip())
l = len(exp)
stack = []

for i in s :
    stack.append(i)
    if stack[-l:] == exp :
        for _ in range(l) :
            stack.pop()

if stack :
    print("".join(stack))
else :
    print("FRULA")