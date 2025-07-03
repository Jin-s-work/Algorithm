
import heapq
import sys
input = sys.stdin.readline

n = int(input())

pq = []
for _ in range(n):
    a = int(input())

    if a > 0:
        heapq.heappush(pq, -a)
    elif a == 0 and pq:
        print(-heapq.heappop(pq))
    elif a == 0 and not pq:
        print(0)

