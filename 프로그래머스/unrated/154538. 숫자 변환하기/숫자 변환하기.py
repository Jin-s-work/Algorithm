def solution(x, y, n):
    answer = 0
    
    dp = [1e8] * (y+1)
    dp[x] = 0
    
    for i in range(x, y+1):
        if dp[i] == 1e8:
            continue
        if i + n <= y:
            dp[i+n] = min(dp[i+n], dp[i] + 1)
        if 2 * i <= y:
            dp[2*i] = min(dp[2*i], dp[i] + 1)
        if 3 * i <= y:
            dp[3*i] = min(dp[3*i], dp[i] + 1)
            
            
          
        
    if dp[y] == 1e8:
        return -1
        
    return dp[y]
        
        
    
