import heapq

def solution(operations):
    heap = []
    max_heap = []
    for k in operations:
        a, b = k.split()
        
        if a == "I":
            heapq.heappush(heap, int(b))
            heapq.heappush(max_heap, (-1 * int(b), int(b)))     
            
        elif a == "D":
            if len(heap) == 0:
                continue
            elif int(b) == 1:
                Max = heapq.heappop(max_heap)[1]
                # -를 해서 넣으므로 원래 값을 하기 위해서 [1]을 한다.
                heap.remove(Max)
                # 최대 최소 모두 지워야 하기에 값을 저장해놓고 지운다.
            elif int(b) == -1:
                Min = heapq.heappop(heap)
                max_heap.remove((-1 * Min, Min))
                           
    if heap:
        return [heapq.heappop(max_heap)[1], heapq.heappop(heap)]
    # 최대 힙의 제일 앞과, 최소 힙의 제일 앞 = (최대, 최소)
    else:
        return [0,0]
                 
        

