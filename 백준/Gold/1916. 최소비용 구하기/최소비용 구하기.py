
import sys
import heapq

n = int(input())
m = int(input())

arr = [[] for _ in range(n + 1)]
for _ in range(m):
    start, end, cost = map(int, input().split())
    arr[start].append((cost, end))
# 우선순위큐에서 최소 비용으로 정렬하기 위해서 (비용, 목적지)로 넣어준다.

start, end = map(int, input().split())

def dijkstra(start):
    dist = [sys.maxsize] * (n + 1)
    pq = []

    # (비용, 시작점)
    heapq.heappush(pq, (0, start))
    dist[start] = 0

    while pq:
        cost, now = heapq.heappop(pq)
        # 지금까지 비용이 가장 작은 노드를 선택한다.

        if dist[now] < cost:
            continue

        for next_cost, next in arr[now]:
            new = cost + next_cost
            if new < dist[next]:
                dist[next] = new
                heapq.heappush(pq, (new, next))

    return dist

ans = dijkstra(start)
print(ans[end])