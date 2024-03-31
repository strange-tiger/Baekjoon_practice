import sys

word = list(sys.stdin.readline().rstrip())
sub = list()

for i in range(1, len(word) - 1):
    for j in range(i + 1, len(word) ):
        a = word[:i]
        b = word[i:j]
        c = word[j:]
        a.reverse()
        b.reverse()
        c.reverse()
        sub.append(''.join(a + b + c))

print(sorted(sub)[0])