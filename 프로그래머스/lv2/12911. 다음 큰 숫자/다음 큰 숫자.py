def solution(n):
    answer = 0
    
    
    num = bin(n).count("1")
    
    while True:
        n += 1
        if num == bin(n).count("1"):
            answer = n
            break
        
    
    return answer