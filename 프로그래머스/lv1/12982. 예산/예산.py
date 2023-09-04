def solution(d, budget):
    answer = 0
    
    d.sort()
    
    num = budget
    for k in d:
        if num >= k:
            num -= k
            answer += 1
        else:
            return answer
        
    
    
    
    return answer