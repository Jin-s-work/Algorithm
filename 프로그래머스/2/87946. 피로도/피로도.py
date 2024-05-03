def solution(k, dungeons):
    global answer
    answer = 0
    
    check = [0] * len(dungeons)
    
    def DFS(k, num, dungeons):
        global answer
        if num > answer:
            answer = num
            
        for i in range(len(dungeons)):
            if k >= dungeons[i][0] and not check[i]:
                check[i] = 1
                DFS(k - dungeons[i][1], num + 1, dungeons)
                check[i] = 0
    
    
    DFS(k, 0, dungeons)
    
    return answer