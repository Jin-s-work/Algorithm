def solution(n, computers):
    answer = 0
    
    def DFS(now):
        check[now] = 1
        for next in range(n):
            if computers[now][next] and not check[next]:
                DFS(next)
                
    
    check = [0] * (n+1)
    
    for i in range(n):
        if not check[i]:
            DFS(i)
            answer += 1
    
    
    return answer