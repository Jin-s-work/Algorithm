
import heapq

n = int(input())
m = int(input())

arr = [[] for _ in range(n + 1)]
for _ in range(m):
    start, end, cost = map(int, input().split())
    arr[start].append((cost, end))
# 우선 순위 큐에서 최소 비용으로 정렬하기 위해 (비용, 목적지)

start, end = map(int, input().split())

INF = 10 ** 18

def dijkstra(start):
    dist = [INF] * (n + 1)
    pq = []

    # 비용, 시작
    heapq.heappush(pq, (0, start))
    dist[start] = 0
    # 처음 우선순위 큐에 (0, start)로 넣는다.

    while pq:
        cost, now = heapq.heappop(pq)
        # 제일 비용이 작은 노드를 선택
        if dist[now] < cost:
            continue

        for next_cost, next in arr[now]:
            new = cost + next_cost
            if new < dist[next]:
                dist[next] = new
                heapq.heappush(pq, (new, next))

    return dist

# 배열을 출력한다.
ans = dijkstra(start)
print(ans[end])



