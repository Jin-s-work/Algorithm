import heapq

def Dijkstra(start, dist, graph):
    q = []
    heapq.heappush(q, (0, start))
    dist[start] = 0
    
    while q:
        distance, now = heapq.heappop(q)
        
        if dist[now] < distance:
            continue
        
        for k in graph[now]:
            cost = distance + k[1]
            if cost < dist[k[0]]:
                dist[k[0]] = cost
                heapq.heappush(q, (cost, k[0]))
            
    

def solution(N, road, K):
    answer = 0

    dist = [int(1e9)] * (N+1)
    graph = [[] for _ in range(N+1)]
    
    for a, b, c in road:
        graph[a].append((b, c))
        graph[b].append((a, c))
    
    Dijkstra(1, dist, graph)
    
    for i in range(1, N+1):
        if dist[i] <= K:
            answer += 1
    
    return answer

# import heapq
# # 파이썬에서는 힙큐를 쓰자..

# def Dijkstra(start, dist, graph):
#     q = []
#     heapq.heappush(q, (0,start))
#     # q라는 힙큐에 (0,start)를 추가해준다.
    
#     dist[start] = 0
#     # 처음인 dist에 start인 경우 0을 대입한다.
    
#     while q:  # q가 없어질때까지 (!q.empty())
#         distance, now = heapq.heappop(q)
#         # q를 pop하면서 distance, now를 빼준다.
#         if dist[now] < distance:
#             continue
#         # 만약 distance가 원래의 dist[now]보다 작을 경우 그냥 넘어감
#         # 아닐 경우에
#         for k in graph[now]:
#             cost = distance + k[1]
#             # graph[now]에 대해 cost = distance + graph[now][1]을 해준다.
#             if cost < dist[k[0]]:  # 만약 이 더해진 cost가 원래보다 작을 경우
#                 dist[k[0]] = cost  # 갱신해주고
#                 heapq.heappush(q, (cost, k[0]))
#             # 큐에 이 k[0] 값을 넣어준다.
# def solution(N, road, K):
#     answer = 0
#     # 다익스트라...

#     # dist는 최대의 수로 리스트를 만들어준다. (N+1)개 만큼
#     dist = [int(1e9)] * (N + 1)
#     graph = [[] for _ in range(N+1)]
#     # 그래프 또한 N+1의 길이를 가진 이중 그래프를 만들어준다.
    
#     for a, b, c in road:
#         graph[a].append((b, c))  # [a][b] == c
#         graph[b].append((a, c))  # [b][a] == c
#         # 양방향에 모두 해준다.

#     Dijkstra(1, dist, graph)
#     # 시작은 1, dist와 graph는 원래대로 넣어준다.
    
#     for i in range(1, N+1):
#         if dist[i] <= K:
#             answer += 1
#     # 1에 관해서 해주면 되기에 dist[i]를 체크하여 K보다 작은 개수를 세준다.
    
#     return answer