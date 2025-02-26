def solution(word):
    answer = 0
    
    alp = "AEIOU"
    arr = []
    
    def DFS(num, k):
        if num == 5:
            return
        
        for i in range(len(alp)):
            arr.append(k + alp[i])
            DFS(num + 1, k + alp[i])

    DFS(0, "")
    answer = arr.index(word) + 1
    
    return answer