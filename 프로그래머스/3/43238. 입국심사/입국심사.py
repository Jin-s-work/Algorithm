def solution(n, times):
    answer = 0
    
    times.sort()
    
    left = 0
    right = times[len(times) - 1] * n
    # 제일 최악의 경우 모든 손님들이 제일 오래걸리는 사람 한테만 가서 받는 경우 따라서 * n
    
    while left <= right:
        mid = (left + right) // 2
        
        num = 0
        for i in range(len(times)):
            num += (mid // times[i])
            # mid만큼 총 걸릴 경우 times들에 대해서 나눈 값들을 모두 더하면 num이 n이 되어야 한다.
            
        if num < n:
            left = mid + 1
        else:
            if mid <= right:
                answer = mid
            # num이 n이상인데, mid가 아직 right 보다 작을 경우 answer를 넣어준다.
        
            right = mid - 1
    
    return answer