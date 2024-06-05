import sys

strings = list()
nums = [0, 0, 0]
for i in range(3):
    strings.append(sys.stdin.readline().rstrip())

    if nums[0] != 0:
        continue
    elif strings[i] != "Fizz" and strings[i] != "Buzz" and strings[i] != "FizzBuzz":
        nums[i] = int(strings[i])

        for j in range(3):
            nums[j] = nums[i] - i + j

num = nums[2] + 1

output = str()

if num % 3 == 0:
    output += "Fizz"
if num % 5 == 0:
    output += "Buzz"

if output == "":
    print(num)
else:
    print(output)