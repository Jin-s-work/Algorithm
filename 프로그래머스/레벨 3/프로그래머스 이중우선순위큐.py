import heapq

def solution(operations):
    answer = []
    
    arr = []
    for k in operations:
        a, b = k.split()
        if a == 'I':
            heapq.heappush(arr,int(b))
        else:
            if not arr:
                continue
            if b == '1':   # b가 1일 경우 최대값을 삭제
                arr.remove(heapq.nlargest(1, arr)[0])
                # 제일 큰 값을 삭제해 준다.
            else:          # b가 -1일 경우 최솟값을 삭제
                heapq.heappop(arr)    # 그냥 바로 pop하면 최솟값 삭제
    
    if arr:
        return [heapq.nlargest(1, arr)[0], arr[0]]
    else:
        return [0,0]
        
