

n = int(input())
arr = list(map(int, input().split()))

dp = arr[:]
# dp = arr을 하면 같이 바껴서 이렇게 넣으면 안되고

for i in range(n):
    for j in range(i):
        if arr[j] < arr[i]:
            dp[i] = max(dp[i], dp[j] + arr[i])
# 이중포문으로 다 찾아준다.
# 그 전의 값중에 작은 값들 중 dp를 비교해서 전의 값에서 와서 더한 값이 더 클 경우에 갱신

print(max(dp))

