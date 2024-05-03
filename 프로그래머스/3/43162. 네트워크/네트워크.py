# def solution(n, computers):
#     answer = 0
    
#     def DFS(now):
#         check[now] = 1
#         for next in range(n):
#             if not check[next] and computers[now][next]:
#                 DFS(next)
    
#     check = [0] * len(computers)
#     for i in range(n):
#         if not check[i]:
#             DFS(i)
#             answer += 1
    
#     return answer

from collections import deque
def solution(n, computers):
    answer = 0
    
    def BFS(computers, check, now):
        q = deque([now])
        check[now] = 1
    
        while q:
            v = q.popleft()
            for i in range(n):
                if not check[i] and computers[v][i]:
                    q.append(i)
                    check[i] = 1
            
    check = [0] * (len(computers) + 1)
    for i in range(n):
        if not check[i]:
            BFS(computers, check, i)
            answer += 1
    
    
    return answer