import heapq

def solution(jobs):
    answer = 0
    
    # 작업 요청 시간이 바로 전에 완료한 작업의 시작 시간 보다 크고, 현재 시점보다 작거나 같아야 한다.
    # 작업의 소요 시간 기준으로 최소 힙을 만들어주어야 한다.
    
    now = 0
    i = 0
    start = -1
    heap = []
    
    while i < len(jobs):
        for j in jobs:
            if start < j[0] <= now:
                heapq.heappush(heap, [j[1], j[0]])
            # job에서의 시작이 start와 now 안에 있을 경우에 넣어준다.
        
        # 처리할 작업이 있는 경우
        if len(heap) > 0:  
            cur = heapq.heappop(heap)
            start = now
            now += cur[0]   # 걸린 시간을 더해준다.
            answer += (now - cur[1]) # 걸린 시간에서 작업 요청 시점을 빼서 (작업의 요청부터 종료까지 걸린 시간)을 answer에 더해준다.
            i += 1
            # job을 처리했으므로 인덱스도 늘려준다.
        else:
            now += 1
        # 처리할 작업이 없으므로 now를 늘려서 작업이 생기는 시점까지 가본다.
    
    # 평균을 구해야 하므로 이렇게
    return int(answer / len(jobs))