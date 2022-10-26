def solution(n, cores):
    
    # cores에는 코어의 처리시간이 담김
    if n <= len(cores):
        return n
    
    else:
        n -= len(cores)
        # 일단 처음에 다 넣는 경우이므로 len(cores) 만큼을 빼준다.
        left = 1
        right = max(cores) * n
        # 최대는 cores에서 제일 큰 경우에 n만큼 곱한 값
        # right = 3 * 6
        while left < right:
            mid = (left + right) // 2
            num = 0
        # mid : 9
        # mid : 5
        # mid : 3
        # mid : 4
            for k in cores:
                num += mid // k
            # num에 mid에 대해서 다 나눈 값들을 더해준다.
        # 9 4 3  num = 16
        # 5 2 1  num = 8
        # 3 1 1  num = 5
        # 4 2 1  num = 7
            if num >= n:        # num이 n보다 더 큰 경우
                right = mid     # 이분 탐색으로 왼쪽으로 간다.
            else:               # num이 더 작은 경우 더 키우기 위해
                left = mid + 1  # 이분 탐색이 오른쪽으로 간다.
        # right = 9 left = 1  while이므로 계속 돌린다.
        # right = 5 left = 1
        # left = 4 right = 5
        # left = 4 right = 4  left < right 가 아니므로 끝..
        
        for k in cores:         # 다 되었을때 제일 큰 right에 대해
            n -= ((right - 1) // k)
            # n -= (right - 1) // k를 전체로 한다.
        # 3 // k   3 1 1
        # n == 1
        for i in range(len(cores)):
            if right % cores[i] == 0:
                n -= 1
                if n == 0:
                    return i+1
            # i = 1일때, n = 1인데, 1빼므로 n이 0이 되고 1+1이 리턴된다.
        
## C++로 했을때는 좀 알았는데 파이썬으로는 엥 싶긴 하다..
## 비슷한 논리일텐데 잘 모르겠다..
