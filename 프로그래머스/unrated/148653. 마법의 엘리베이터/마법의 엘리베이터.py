def solution(storey):
    answer = 0
    
    while storey:
        rem = storey % 10
    
        if rem > 5:
            answer += (10 - rem)
            storey += 10
        elif rem < 5:
            answer += rem
        else:
            if (storey // 10) % 10 >= 5:
                storey += 10
            answer += rem
        
        storey //= 10
    
    
    
    
    
    return answer