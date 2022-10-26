def solution(stones, k):

    # DP인듯  -> DP로도 할 수 있지만 이분탐색이다..
    # 한번 밟을때마다 1씩 줄어든다.
    # 숫자가 0이되면 밟을 수 없다.
    # 가까운 디딤돌로만 가능하다.
    
    start = 1
    end = max(stones)
    
    while start <= end:
        num = 0
        mid = (start + end) // 2
        for t in stones:
            if (t - mid) <= 0:     # 뺀 값이 0이하일 경우
                num += 1           # num을 증가시켜준다.
            else:
                num = 0   # 끊긴 경우 다시 0으로 한다.
            if num >= k:
                break     # num이 k보다 클 경우 안되므로 break
                          # 이때의 start를 알면 된다.
                
        if num >= k:
            end = mid - 1
            # num이 k 이상일 경우 최댓값을 줄인다.
        else:
            start = mid + 1
            # num이 k보다 작을 경우 mid명이 징검거리를 통과하는 것이 가능하므로
            # 최솟값을 올린다.
    
    return start
    # 여기서의 start는 값이다.
















