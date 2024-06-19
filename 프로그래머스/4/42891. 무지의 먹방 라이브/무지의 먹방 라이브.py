import heapq

def solution(food_times, k):
    
    if sum(food_times) <= k:
        return -1
    
    q = []
    for i in range(len(food_times)):
        heapq.heappush(q, (food_times[i], i + 1))
        # (음식 시간, 음식 번호)
    
    eat = 0
    previous = 0
    remain = len(food_times)
    
    while (eat + ((q[0][0] - previous) * remain) <= k):
        now = heapq.heappop(q)[0]
        eat = eat + (now - previous) * remain
        remain = remain - 1
        previous = now
        
    answer = sorted(q, key=lambda x : x[1])
    
    return answer[(k - eat) % remain][1]