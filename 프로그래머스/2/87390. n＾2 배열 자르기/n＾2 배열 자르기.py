def solution(n, left, right):
    answer = []
    
    
    for k in range(left, right + 1):
        a = k // n
        b = k % n
        
        if a >= b:
            answer.append(a + 1)
        else:
            answer.append(b + 1)
    
    return answer