import sys

vowels = ['a','e','i','o','u']
accept = ['ee','oo']

while True :
    threeRow, twoRow = False, False
    password = sys.stdin.readline().rstrip()
    if password == 'end' :
        break

    cnt = 0
    for i in vowels :
        if i in password :
            cnt += 1

    if cnt < 1 :
        print(f'<{password}> is not acceptable.')
        continue

    for i in range(len(password) - 2) :
        if password[i] in vowels and password[i + 1] in vowels and password[i + 2] in vowels :
            threeRow = True
        elif not(password[i] in vowels) and not(password[i + 1]in vowels) and not(password[i + 2] in vowels) :
            threeRow = True
    if threeRow :
        print(f'<{password}> is not acceptable.')
        continue

    for i in range(len(password) - 1) :
        if password[i] == password[i + 1] :
            if password[i] == 'e' or password[i] == 'o' :
                continue
            else :
                twoRow = True
    if twoRow :
        print(f'<{password}> is not acceptable.')
        continue
    print(f'<{password}> is acceptable.')