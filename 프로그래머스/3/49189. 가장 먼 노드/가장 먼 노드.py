
from collections import deque

def solution(n, edge):
    answer = 0
    
    arr = [[] for _ in range(n+1)]
    check = [0] * (n+1)
    
    for k in edge:
        arr[k[0]].append(k[1])
        arr[k[1]].append(k[0])
    
    check[1] = True
    q = deque([1])
    
    while q:
        now = q.popleft()
        
        for next in arr[now]:
            if not check[next]:
                check[next] = check[now] + 1
                q.append(next)
        
    Max = max(check)
    answer = check.count(Max)
    
    if answer >= 0:
        return answer
    else:
        return -1
    
    