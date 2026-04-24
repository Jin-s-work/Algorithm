def solution(cost, hint):
    answer = 0
    
    # 각 스테이지를 순서대로 모두 해결해야 한다.
    # i번 힌트권은 오직 i번 스테이지에서 사용이 가능
    # 하나의 스테이지에서 n-1개의 힌트권만 사용 가능
    
    # 힌트 번들은 최대 1개 구매가 가능,,
    # 힌트 번들은 이후 스테이지의 힌트권을 제공하며 비용을 줘야함
    
    # 각각의 힌트 번들을 사야하는지 안사야 하는지
    # dp로 풀어야 하는지,, DFS로 풀어야 하는지 어렵다
    
    # i번 스테이지일 때 쿠폰이 j개 있을때의 비용
    # cost[i][j]
    
    n = len(cost)
    
    def DFS(stage, hints):
        if stage == n:
            return 0 
        
        use = min(hints[stage], n-1)
        clear_cost = cost[stage][use]
        
        # 번들 안사는 경우
        best = clear_cost + DFS(stage + 1, hints)
        
        # 번들 사는 경우
        if stage < n-1:
            new_hint = list(hints)
            
            for target in hint[stage][1:]:
                new_hint[target-1] += 1
            
            bundle = hint[stage][0]
            best = min(best, clear_cost + bundle + DFS(stage + 1, tuple(new_hint)))
        
        return best

    start_hint = tuple([0] * n)
    
    
    return DFS(0, start_hint)