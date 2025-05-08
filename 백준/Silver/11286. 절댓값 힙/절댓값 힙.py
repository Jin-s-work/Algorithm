
import heapq
import sys
input = sys.stdin.readline

n = int(input())

pq = []

for _ in range(n):
    x = int(input())
    if x != 0:
        heapq.heappush(pq, (abs(x), x))
    else:
        if pq:
            print(heapq.heappop(pq)[1])
        else:
            print(0)
