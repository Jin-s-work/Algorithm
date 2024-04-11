def solution(triangle):
    answer = 0
    
    n = len(triangle)
    dp = [[0] * (n + 1) for _ in range(n+1)]
    
    dp[0][0] = triangle[0][0]
    for i in range(1, len(triangle)):
        for j in range(i+1):
            if j == 0:
                dp[i][j] = dp[i-1][0] + triangle[i][j]
            elif i == j:
                dp[i][j] = dp[i-1][j-1] + triangle[i][j]
            else:
                dp[i][j] = max(dp[i-1][j-1], dp[i-1][j]) + triangle[i][j]
    
    answer = max(dp[n-1])
    
    return answer