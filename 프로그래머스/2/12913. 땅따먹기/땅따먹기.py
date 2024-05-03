def solution(land):
    answer = 0

    n = len(land)
    dp = [[0] * len(land[0]) for _ in range(len(land))]
    
    dp[0][0] = land[0][0]
    dp[0][1] = land[0][1]
    dp[0][2] = land[0][2]
    dp[0][3] = land[0][3]
    
    for i in range(len(land)-1):
        dp[i+1][0] = land[i+1][0] + max(dp[i][1], dp[i][2], dp[i][3])
        dp[i+1][1] = land[i+1][1] + max(dp[i][0], dp[i][2], dp[i][3])
        dp[i+1][2] = land[i+1][2] + max(dp[i][1], dp[i][3], dp[i][0])
        dp[i+1][3] = land[i+1][3] + max(dp[i][0], dp[i][2], dp[i][1])
    
    answer = max(dp[n-1][0], dp[n-1][1], dp[n-1][2], dp[n-1][3])

    return answer