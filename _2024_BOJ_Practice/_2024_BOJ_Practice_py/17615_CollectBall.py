import sys

N = int(sys.stdin.readline().rstrip())
ball = sys.stdin.readline().rstrip()
cnt = []

cnt.append(ball.rstrip('R').count('R'))
cnt.append(ball.lstrip('R').count('R'))
cnt.append(ball.rstrip('B').count('B'))
cnt.append(ball.lstrip('B').count('B'))

print(min(cnt))