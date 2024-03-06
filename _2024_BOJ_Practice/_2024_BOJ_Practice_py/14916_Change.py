import sys

change = int(sys.stdin.readline().rstrip())

five = change // 5
two = change % 5

if two % 2 != 0 :
    if (two + 5) % 2 == 0 and five > 0 :
        five -= 1
        two = (two + 5) // 2
    else :
        five = 0
        two = -1
else :
    two = two // 2

print(five + two)