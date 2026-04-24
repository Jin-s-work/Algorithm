def solution(signals):
    answer = 0
    
    # 처음에는 모두 초록불
    # 모든 신호등이 노란불이 되면 정전
    # 신호등 최대 5개
    
    # g + (g + r)t 부터 g + (g + y + r)t 안에 들어가면 된다..?
    
    def gcd(a, b):
        while b > 0:
            a, b = b, a % b
        return a
    
    n = len(signals)
    limit = 1
    for g, y, r in signals:
        cycle = g + y + r
        limit = (limit * cycle) // gcd(limit, cycle)
    
    for t in range(1, limit + 1):
        check = True
        
        for g, y, r in signals:
            cycle = g + y + r
            now = (t - 1) % cycle
            
            if not (g <= now < g + y):
                check = False
                break
            
        if check:
            return t
    
    return -1
    
    
    
    
    
    
    return answer