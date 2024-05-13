def solution(n):
    answer = ''
    
    # 0 1 3
    # 3진법 + 1
    
    num = n
    while num > 0:
        div = num % 3
        num //= 3
        
        if div == 0:
            answer = "4" + answer
            num -= 1
        elif div == 2:
            answer = "2" + answer
        elif div == 1:
            answer = "1" + answer
    
    
    return answer