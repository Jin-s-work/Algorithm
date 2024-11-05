

# 주식 하나를 산다.
# 원하는 만큼 가지고 있는 주식을 판다
# 아무것도 안한다

t = int(input())

answer = []
for _ in range(t):
    n = int(input())
    arr = list(map(int, input().split()))

    dp = [0] * n
    dp[n-1] = arr[n-1]
    for i in range(n-2, -1, -1):
        dp[i] = max(arr[i], dp[i + 1])

    ans = 0
    for i in range(n):
        ans += dp[i] - arr[i]

    answer.append(ans)

for k in answer:
    print(k)