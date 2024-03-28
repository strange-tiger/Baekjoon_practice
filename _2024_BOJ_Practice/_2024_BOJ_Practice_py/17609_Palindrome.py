# 17609_Palindrome.py

import sys

T = int(sys.stdin.readline().rstrip())

for _ in range(T) :
    BREAK = False
    s = sys.stdin.readline().rstrip()

    begin = 0
    end = len(s) - 1

    while s[begin] == s[end] :
        begin += 1
        end -= 1

        if begin == end or begin - end == 1 :
            BREAK = True
            print(0)
            break
    if BREAK :
        continue

    for i in range(len(s)) :
        begin = 0
        end = len(s) - 1

        if i == begin :
            begin += 1
        elif i == end :
            end -= 1

        while s[begin] == s[end] :
            begin += 1
            end -= 1

            if i == begin :
                begin += 1
            elif i == end :
                end -= 1
            #print(begin, end)
            if begin == end or begin - end == 1 :
                BREAK = True
                print(1)
                break
        if BREAK :
            break
    if BREAK :
            continue

    print(2)