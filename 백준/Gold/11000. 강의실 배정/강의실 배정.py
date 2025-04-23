
import heapq
n = int(input())

arr = []
for _ in range(n):
    a, b = map(int, input().split())
    arr.append((a, b))
arr.sort()

heap = []
for start, end in arr:
    if heap and heap[0] <= start:
        heapq.heappop(heap)
    heapq.heappush(heap, end)

print(len(heap))

# 우선 순위 큐를 사용해서 가장 빨리 끝나는 수업시간을 계속 관리하는 것이다.
# 우선 순위큐를 사용하면 O(1)에 꺼낼 수 있고, O(logn)에 업데이트가 가능하다.
# 사용하는 이유 : 가장 빨리 끝나는 수업보다 늦게 시작하면 그 강의실을 재사용이 가능
# 우선 순위큐가 아니면 전체확인해야 하는데 이는 O(n^2)