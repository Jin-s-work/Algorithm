
import heapq
t = int(input())

for _ in range(t):
    k = int(input())
    arr = list(map(int, input().split()))

    ans = 0
    pq = []
    for k in arr:
        heapq.heappush(pq, k)

    while len(pq) > 1:
        one = heapq.heappop(pq)
        two = heapq.heappop(pq)
        s = one + two
        heapq.heappush(pq, s)
        ans += s

    print(ans)