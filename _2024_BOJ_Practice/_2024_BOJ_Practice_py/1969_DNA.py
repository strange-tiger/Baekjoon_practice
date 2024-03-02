import sys

N, M = map(int, input().split())
answer = ""
hammingDist = 0
nucleotide = ['A', 'C', 'G', 'T'] # 여러 개의 DNA가 답으로 가능할 때 사전순으로 앞서는 것을 출력하기 위한 배열 순서
dna = []
cnt = [0, 0, 0, 0]

for _ in range(N) :
    dna.append(input())

for i in range(M) :
    for str in dna :
        for j in range(4) :
            if str[i] == nucleotide[j] :
                cnt[j] += 1

    answer += nucleotide[cnt.index(max(cnt))]
    cnt = [0 for _ in range(4)]

    for str in dna :
        if str[i] != answer[i] :
            hammingDist += 1

print(answer)
print(hammingDist)