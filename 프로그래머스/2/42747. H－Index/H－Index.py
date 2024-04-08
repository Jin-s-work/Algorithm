def solution(citations):
    answer = 0
    
    citations.sort(reverse=True)
    
    # 6 5 3 1 0 
    
    for i in range(len(citations)):
        if citations[i] >= i + 1:
            answer += 1            
    
    return answer