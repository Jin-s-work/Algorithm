def solution(distance, rocks, n):
    answer = 0
    
    rocks.sort()
    
    left = 0
    right = distance
    
    while left <= right:
        mid = (left + right) // 2
        
        num = 0
        dist = 0
        
        for i in range(len(rocks)):
            if rocks[i] - dist < mid:
                num += 1
            # 차이가 mid보다 작을 경우 바위를 없애도 되므로 num을 증가시킴
            else:
                dist = rocks[i]
            # 차이가 mid 보다 클 경우 바위를 제거하지 않아도 되므로 rocks[i]를 넣어준다.
            
        if distance - dist < mid:
            num += 1
        # 맨 마지막의 경우도 끝인 distance와 비교 해야한다.
        
        if num <= n:
            answer = max(answer, mid)
            left = mid + 1
        else:
            right = mid - 1
    
    
    
    return answer