def solution(m, n, puddles):
    answer = 0
    
    # 좌표가 반대로 되어있으므로 반대로 해주어야한다.
    puddles = [[q, p] for [p,q] in puddles]
    dp = [[0] * (m+1) for _ in range(n+1)]
    dp[1][1] = 1
    
    for i in range(1,n+1):
        for j in range(1,m+1):
            if i == 1 and j == 1:
                continue
            if [i,j] in puddles:
                dp[i][j] = 0
            else:
                dp[i][j] = (dp[i-1][j] + dp[i][j-1]) % 1000000007
    
    
    return dp[n][m]
