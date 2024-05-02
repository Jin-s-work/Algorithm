def solution(word):
    answer = 0
    
    arr = []
    words = "AEIOU"
    
    def DFS(num, k):
        if num == 5:
            return
        
        for i in range(len(words)):
            arr.append(k + words[i])
            DFS(num + 1, k + words[i])
        # 처음에 A 넣고, AA, AAA, AAAA, AAAAA
        # AAAAA에서 돌아와서 그 다음인 E로 넣는다. 따라서 AAAAE, 5개이므로 끝나니까 다음인 I
        # AAAAI,,,, AAAAO, AAAAU, 다음은 AAAE
    
    DFS(0, "")
    answer = arr.index(word) + 1
    
    
    return answer