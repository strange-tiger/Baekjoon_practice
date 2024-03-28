import sys

S = sys.stdin.readline().rstrip()
cnt = [0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0]
for i in S :
    cnt[ord(i) - ord('a')] += 1

ans = ""
for i in cnt :
    ans += str(i)
    ans += ' '

print(ans)

# ord(), chr() 함수
# https://velog.io/@zionhann/%ED%8C%8C%EC%9D%B4%EC%8D%AC-%EC%9C%A0%EB%8B%88%EC%BD%94%EB%93%9C-%EB%AC%B8%EC%9E%90-%EB%B3%80%ED%99%98%ED%95%98%EA%B8%B0