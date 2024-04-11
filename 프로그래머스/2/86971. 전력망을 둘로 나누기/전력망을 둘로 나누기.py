
from collections import deque

def BFS(start, check, arr):
    q = deque([start])
    check[start] = 1
    result = 1
    
    while q:
        now = q.popleft()
        for i in arr[now]:
            if not check[i]:
                result += 1
                q.append(i)
                check[i] = True
    
    return result

def solution(n, wires):
    answer = n
    
    arr = [[] for _ in range(n+1)]
            
    for a, b in wires:
        arr[a].append(b)
        arr[b].append(a)
        
    for start, not_check in wires:
        check = [0] * (n+1)
        check[not_check] = True
        # not check하는 부분은 일단 이 경우에는 True로 한번만 빼주고 BFS하면 넘어간다.
        # 굳이 for문을 두번할 필요가 없음
        result = BFS(start, check, arr)
    
        # 차이가 작을 경우 갱신한다.
        if abs(result - (n - result)) < answer:
            answer = abs(result - (n - result))
    
    
    
    
    return answer