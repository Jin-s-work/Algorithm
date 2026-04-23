def solution(n, infection, edges, k):
    answer = 0
    
    # 처음에 infection에서부터 시작해서 k번만에 최대 감염이 일어나게하기
    # 원래는 arr[a].append(b)이런식으로 넣어주는데 여기에서는 type도 넣어야하므로
    # arr[a].append((b, t)) 이런식으로 할까?
    
    arr = [[] for _ in range(n + 1)]
    for a, b, t in edges:
        arr[a].append((b, t))
        arr[b].append((a, t))
    
    infect = {infection}
    
    # 여기에서는 DFS에서 각각 어떻게 오픈할지를 계산하는 함수
    def spread(infect, type):
        new_infect = set(infect)
        q = list(infect)
        
        while q:
            now = q.pop()
            for next, t in arr[now]:
                if t == type and next not in new_infect:
                    new_infect.add(next)
                    q.append(next)
            
        return new_infect
            
    
    # 여기에는 몇번을 열었는지와 감염된 것들을 해주는 DFS
    def DFS(infect, t):
        if t == k:
            return len(infect)
        
        best = len(infect)
        for pipe_type in [1, 2, 3]:
            next_infect = spread(infect, pipe_type)
            
            if next_infect == infect:
                continue
                
            best = max(best, DFS(next_infect, t + 1))
        
        return best


    return DFS(infect, 0)