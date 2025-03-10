

t = int(input())

dp = [[0] * 3 for _ in range(10001)]
dp[0][0] = 1
# dp[i][j]는 i를 1,2,3을 이용해서 만들고 마지막 1,2,3 중 하나가 오는 경우의 수
# j+1이 마지막으로 추가되는 숫자이다.

# dp[1][0] = 1 : 1을 만들 수 있는 유일한 방법은 1
# dp[2][0] = 1, dp[2][1] = 1 : [1+1], [2]
for i in range(1, 10001):
    dp[i][0] = dp[i-1][0]
    # 마지막에 1이 오는 경우에는 i-1을 만들고, 1을 더하는 경우

    if i > 1:
        dp[i][1] = dp[i-2][0] + dp[i-2][1]
        # i-2에서 i가 되려면 2를 더해주어야 하는데 이를 위해 1로 끝난 수 + 2로 끝난 수
    if i > 2:
        dp[i][2] = dp[i-3][0] + dp[i-3][1] + dp[i-3][2]

for _ in range(t):
    a = int(input())
    print(dp[a][0] + dp[a][1] + dp[a][2])


# 1 2 4 6 10

