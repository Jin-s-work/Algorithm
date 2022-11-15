import heapq
def solution(n, works):
    answer = 0
    
    # 야근 피로도는 야근을 시작한 시점에서 남은 일의 작업량을 제곱해서 더한 값
    # 1시간 동안 작업량 1만큼을 처리 가능
    # 야근 피로도를 최소화 해야 햔다.
    
    if sum(works) < n:
        return 0
    
    # heapq를 사용하는데 이는 우선순위 큐 이므로, 마이너스를 붙여서 최대값 기준으로 정렬한 효과 냄
    arr = [-k for k in works]   # 마이너스로 해서 arr에 works의 값들을 넣어준다.
    heapq.heapify(arr)
    # arr을 heapq로 만들어주는 것
    
    while n > 0:           # 오름차순으로 되는데 마이너스를 넣으면 제일 큰 값이 제일 앞이다.
        Max = heapq.heappop(arr)      # 우선순위큐에 있으므로 Max는 pop해준 것..
        heapq.heappush(arr, Max + 1)   # arr에 Max+1을 넣어준다는 뜻
        n -= 1
        # Max - 1이 아니라 Max + 1을 해주는 것은 음수로 넣어서 1빼주기 위해서는 1을 더해주어야..
        # 반복문을 통하여 n만큼 heap에서 최솟값을 뽑아내고,
        # 1을 더해서 넣어준다.
    
    for k in arr:
        answer += k ** 2
    
    return answer

# 처음했던 제일 큰 값을 1씩 줄여주면 시간복잡도는 O(n * mlogm)
