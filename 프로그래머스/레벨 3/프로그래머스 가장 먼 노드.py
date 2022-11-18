from collections import deque
def solution(n, edge):
    answer = 0
    
    check = [0] * (n+1)
    arr = [[] for _ in range(n+1)]
    
    for k in edge:
        arr[k[0]].append(k[1])
        arr[k[1]].append(k[0])
    
    check[1] = 1
    q = deque([1])
    # 1이 시작 하는 부분
    
    while q:
        now = q.popleft()
        for next in arr[now]:      # arr[now]에서의 값에 대해
            if not check[next]:    # 이어지는 check[next]가 아직 0일 경우
                check[next] = check[now] + 1    # 이어주고
                q.append(next)      # 다음 값을 queue에 넣어준다.
                
    Max = max(check)    # check의 값들 중 제일 큰 값을 Max로
    answer = check.count(Max)      # Max의 개수를 세서 answer에 넣는다.
    # 거리들 중 가장 멀리 떨어진 거리를 구해서 그 거리만큼의 노드를 answer에 넣는 것이다.
    
    
    if answer >= 0:
        return answer
    else:
        return 1
    
