def solution(n, left, right):
    answer = []
        
    # 0 1 2   0  1   2  3
    # 3 4 5   4  5   6  7
    # 6 7 8   8  9  10 11
    #         12 13 14 15
    # 위치 // n, 위치 % n 중 더 큰 것을 넣어준다.
    for k in range(left, right+1):
        a = k // n
        b = k % n
        if a >= b:      ## 1 더해주고 넣어야한다. 둘다
            answer.append(a+1)
        else:
            answer.append(b+1)
    
    
    return answer
