
# def solution(n, computers):
#     answer = 0
    
#     def DFS(now):
#         check[now] = 1     # now를 True로 해주고
#         for next in range(n):
#             if computers[now][next] and not check[next]:
#                 DFS(next)
#             # computers가 1이고, check가 아직 방문이 안 된경우에
#             # DFS로 다음으로 가준다.
    
#     check = [0 for _ in range(len(computers))]
    
#     for i in range(n):
#         if not check[i]:
#             DFS(i)
#             answer += 1
#         # check가 아직 방문되지 않을 경우 DFS를 해주고, answer를 증가시킨다.
    
#     return answer

from collections import deque

def solution(n, computers):
    answer = 0
    check = [0] * (n+1)

    
    def BFS(computers, check, now):
        q = deque([now])
        check[now] = 1
        
        while q:
            v = q.popleft()
            for i in range(n):
                if computers[v][i] and not check[i]:
                    q.append(i)
                    check[i] = 1
                
    for i in range(n):
        if not check[i]:
            BFS(computers, check, i)
            answer += 1
    
    
    return answer


# def solution(n, computers):
#     answer = 0
    
#     def DFS(now):
#         check[now] = 1
#         for next in range(n):
#             if computers[now][next] and not check[next]:
#                 DFS(next)
                
    
#     check = [0] * (n+1)
    
#     for i in range(n):
#         if not check[i]:
#             DFS(i)
#             answer += 1
    
    
#     return answer