import math

def solution(r1, r2):
    answer = 0
    
    for i in range(0, r1):
        answer += int(math.sqrt(r2*r2 - i*i)) - int(math.sqrt(r1*r1 - i*i - 1))
    for i in range(r1, r2):
        answer += int(math.sqrt(r2*r2 - i*i))
            
    
    
    
    
    return answer * 4