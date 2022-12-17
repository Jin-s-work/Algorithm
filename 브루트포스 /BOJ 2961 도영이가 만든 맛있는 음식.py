from itertools import combinations
n = int(input())
arr = []
# 사실 10! 자체가 엄청나게 크지는 않아서 combination로 해보기
for _ in range(n):
    arr.append(list(map(int, input().split())))
    # 신맛은 곱이고 쓴맛은 합

comb = []
for i in range(1, n+1):
    comb.append(combinations(arr, i))

ans = 1000000000
for i in comb:
    for j in i:
        sour = 1
        bit = 0
        for k in j:
            sour *= k[0]
            bit += k[1]
        
        ans = min(ans, abs(sour - bit))
        # combination에 관하여 각각 다 곱하거나 더하면서
        # 제일 작은 경우를 ans에 갱신해준다.

print(ans)