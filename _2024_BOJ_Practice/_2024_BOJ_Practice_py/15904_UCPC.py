import sys

str = input()

initial = "UCPC"
idx = 0

for i in str :
    if idx > 3 :
        break
    if i == initial[idx] :
        idx += 1

if idx >= 4 :
    print("I love UCPC")
else :
    print("I hate UCPC")