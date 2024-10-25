


n, k = map(int, input().split())

arr = []
for i in range(n):
    w, v = map(int, input().split())
    arr.append((w, v))

dp = [0] * 100001

for i in range(n):
    for j in range(k,-1, -1):
        if j >= arr[i][0]:
            dp[j] = max(dp[j], dp[j - arr[i][0]] + arr[i][1])
        # if 조건으로 j >= arr[i][0]을 하던 for문에서 막아주던 배열에서 0 이하가 안되게 해줘야 한다.
        
print(max(dp))

# 여기에서 아이템을 한번씩만 사용할 수 있으므로 이것은 0-1 knapsack 문제이다.
# 아이템을 한번씩만 사용할 수 있는 경우에는 중복으로 사용하면 안되기에
# 뒤에서 부터 역순으로 하는 방법을 사용해야 한다.