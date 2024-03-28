# 17413_WordReversal2.py

import sys
S = sys.stdin.readline().rstrip()

stack = list()
answer = ""
rev = True

for i in S :
    if i == '<' :
        rev = False
        for _ in range(len(stack)) :
            answer += stack.pop()

    stack.append(i)
    if i == '>':
        rev = True
        for _ in range(len(stack)) :
            answer += stack.pop(0)
                # 0번 자리(앞, 처음)부터 출력 후 삭제
    elif i == ' ' and rev :
        stack.pop()
        for i in range(0, len(stack)) :
            answer += stack.pop()
        answer += ' '

if stack :
    for _ in range(len(stack)):
        answer += stack.pop()

print(answer)

# 스택처럼 리스트를 사용해 괄호 문제를 해결, 괄호 안은 선입선출로 변경
#
# 리스트 연산, 리스트 연관 함수
# https://daekyoulibrary.tistory.com/entry/Python-%EB%A6%AC%EC%8A%A4%ED%8A%B8list-%EC%97%B0%EC%82%B0-insert-pop-remove-reverse-sort-index-count