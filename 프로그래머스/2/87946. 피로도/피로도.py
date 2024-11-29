def solution(k, dungeons):
    
    global answer
    answer = 0
    
    check = [0] * (len(dungeons) + 1)
    def DFS(k, num, dungeons):
        global answer
        answer = max(answer, num)
        
        for i in range(len(dungeons)):
            if k >= dungeons[i][0] and not check[i]:
                check[i] = True
                DFS(k - dungeons[i][1], num + 1, dungeons)
                check[i] = False
        
    DFS(k, 0, dungeons)
    
    
    return answer