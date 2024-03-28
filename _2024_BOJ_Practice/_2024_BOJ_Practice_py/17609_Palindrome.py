# 17609_Palindrome.py

import sys

def isPalindrome (s = str()) :
    if s == s[::-1] :
        return 0
    else :
        begin = 0
        end = len(s) - 1
        while begin < end :
            if s[begin] == s[end] :
                begin += 1
                end -= 1
            else :
                if s[begin] == s[end - 1] :
                    temp = s[begin:end]
                    if temp == temp[::-1] :
                        return 1
                if s[begin + 1] == s[end] :
                    temp = s[begin + 1 : end + 1]
                    if temp == temp[::-1] :
                        return 1
                return 2

T = int(sys.stdin.readline().rstrip())

for _ in range(T) :
    S = sys.stdin.readline().rstrip()
    print(isPalindrome(S))