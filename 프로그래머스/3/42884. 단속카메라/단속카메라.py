def solution(routes):
    answer = 1
    
    routes.sort()
    start = routes[0][1]
    
    for i in range(1, len(routes)):
        if routes[i][1] < start:
            start = routes[i][1]
        
        if routes[i][0] > start:
            answer += 1
            start = routes[i][1]
    
    
    
    
    
    return answer