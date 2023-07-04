def solution(k, d):
    answer = 0
    
    for num in range(0, d+1, k):
        div = int((d * d) - (num * num)) ** (1 / 2)
        
        answer += (div // k + 1)
    
    
    return answer