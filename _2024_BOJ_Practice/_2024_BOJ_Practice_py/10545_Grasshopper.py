import sys

Input = input().split()
Output = input()

keys = {'null':""}
for i in range(0, 8):
    if i < 5:
        for j in range(0, 3):
            keys[chr(ord('a') + 3 * i + j)] = str(Input.index('%d'%(i + 2)) + 1) * (j + 1)
    elif i == 5:
        for j in range(0, 4):
            keys[chr(ord('a') + 3 * i + j)] = str(Input.index('%d'%(i + 2)) + 1) * (j + 1)
    elif i == 6:
        for j in range(1, 4):
            keys[chr(ord('a') + 3 * i + j)] = str(Input.index('%d'%(i + 2)) + 1) * j
    elif i == 7:
        for j in range(1, 5):
            keys[chr(ord('a') + 3 * i + j)] = str(Input.index('%d'%(i + 2)) + 1) * j

answer = ""
for c in Output:
    if len(answer) > 0 and answer[len(answer) - 1] == keys[c][0]:
        answer += "#"
    answer += keys[c]

print(answer)