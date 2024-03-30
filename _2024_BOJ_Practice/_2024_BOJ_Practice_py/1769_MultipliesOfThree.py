import sys

X = sys.stdin.readline().rstrip()

cnt = 0
while len(X) > 1 :
    cnt += 1
    num = 0
    for i in X :
        num += int(i)
    X = str(num)

print(cnt)
if int(X) % 3 == 0 :
    print("YES")
else :
    print("NO")