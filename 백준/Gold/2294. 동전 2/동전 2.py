

n, k = map(int, input().split())

arr = []
for _ in range(n):
    a = int(input())
    arr.append(a)

# 동전의 개수가 최소
dp = [float('inf')] * (k + 1)
dp[0] = 0

for i in range(1, k + 1):
    for j in range(n):
        if i - arr[j] >= 0:
            dp[i] = min(dp[i], dp[i - arr[j]] + 1)

if dp[k] == float('inf'):
    print(-1)
else:
    print(dp[k])

# dp의 대부분의 쉬운 문제들은 다 이런 식