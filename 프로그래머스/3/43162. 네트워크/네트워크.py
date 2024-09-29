def solution(n, computers):
    answer = 0
    
    def DFS(now):
        check[now] = 1
        for next in range(n):
            if not check[next] and computers[now][next]:
                DFS(next)
    
    
    check = [0] * len(computers)
    for i in range(n):
        if not check[i]:
            DFS(i)
            answer += 1
    
    
    return answer