
from collections import deque
n, m = map(int, input().split())

arr = [[] for _ in range(n + 1)]
in_degree = [0] * (n + 1)
for _ in range(m):
    a, b = map(int, input().split())
    arr[a].append(b)
    in_degree[b] += 1
    # b의 진입차수 증가

q = deque()
ans = []

# 진입 차수가 0인 노드를 큐에 삽입한다.
for i in range(1, n + 1):
    if in_degree[i] == 0:
        q.append(i)

# 큐에서 하나씩 꺼내며 위상 정렬 수행
while q:
    now = q.popleft()
    ans.append(now)

    # 꺼낸 노드와 연결된 간선을 제거
    for next in arr[now]:
        in_degree[next] -= 1
        if in_degree[next] == 0:
            q.append(next)

for k in ans:
    print(k, end = " ")
