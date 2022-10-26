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
            # 이것은 즉 mid // core로 계산한 몫의 누적합이다..
            # 이것을 더한 값,, 즉 연산한 시간들이 n보다 클 경우 왼쪽으로 가면 되고
            # 더 작을 경우에는 오른쪽으로 가서 줄이는 식으로 하면 되는 것이다.
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
        
        # 이분탐색을 이렇게 마치고 나서는 right 값에 작업량을 커버할 수 있는
        # 마지노선 시간이 담기게 된다. 이를 다 빼서 n을 구할 수가 있다.
        # right가 운이 좋게 마지막 작업을 처리하는 코어가 있을 수도 있지만
        # 이 값이 항상 일치한다는 것을 보장할 수 없다.
        # 따라서 right의 시간이 작업량보다 더 많은 작업을 처리한 시간대를
        # 가리킬 수가 있다. 따라서 right - 1의 시간대에서 처리된 작업량의 수를
        # 먼저 구해주어야 한다. 이전의 작업량 수를 계산하고 이 값이 얼마나 차이나는지
        # 를 통해 마지막 작업을 처리할 수 잇는 코어의 위치를 계산할 수 있다.
        
        ## 여기서는 즉 마지막 작업 처리 코어의 위치를 구한다.
        for k in cores:         # 다 되었을때 제일 큰 right에 대해
            n -= ((right - 1) // k)
            # n -= (right - 1) // k를 전체로 한다.
        # 3 // k   3 1 1
        # n == 1
        for i in range(len(cores)):
            if right % cores[i] == 0:  # cores[i]에 관해 탐색하며
                n -= 1                 # 나머지가 0이 될 경우 1씩 줄인다.
                if n == 0:
                    return i+1
                # 0이 될 경우 이 경우의 인덱스 + 1을 리턴한다.
            # i = 1일때, n = 1인데, 1빼므로 n이 0이 되고 1+1이 리턴된다.
        
        # 결국 마지막 이 for문을 설명하려면 현재 시간과 코어의 처리시간이 나누어 떨어지는 순간에
        # 새 작업을 할당하기 때문에 남아있는 작업의 수를 1 줄이고
        # 만약 이때 남아있는 작업이 0이 되는 지점이라면 해당 코어의 인덱스를 반환한다.
        # 여기서 인덱스를 1부터 시작하게 설정하였으므로 인덱스에 1을 더한 값을 반환한다.
        # 제일 참고한 블로그 : https://velog.io/@longroadhome/%ED%94%84%EB%A1%9C%EA%B7%B8%EB%9E%98%EB%A8%B8%EC%8A%A4-LV.4-%EC%84%A0%EC%9E%85-%EC%84%A0%EC%B6%9C-%EC%8A%A4%EC%BC%80%EC%A4%84%EB%A7%81-JS
