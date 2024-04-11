def solution(word):
    answer = 0
    
    # 5진법?
    arr = []
    words = "AEIOU"
    
    def DFS(num, k):
        if num == 5:
            return
        for i in range(len(words)):
            arr.append(k + words[i])
            DFS(num + 1, k + words[i])
    
    DFS(0, "")
    answer = arr.index(word) + 1
    # arr에서 word의 위치를 찾아서 1을 더해주면 된다.
    
    return answer