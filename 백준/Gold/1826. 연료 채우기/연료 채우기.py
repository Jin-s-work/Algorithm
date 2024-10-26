
import heapq
n = int(input())

arr = []
for i in range(n):
    a, b = map(int, input().split())
    arr.append((a, b))
    # 시작 위치에서 주유소까지의 거리
    # 주유소에서 채울 수 있는 연료의 양

l, p = map(int, input().split())
# 원래의 위치에서 마을까지의 거리
# 트럭에 원래 있던 연료의 양

arr.sort()
q = []

ans = 0
idx = 0
now = p
# now는 연료의 양이다.


while now < l:
    # 현재의 위치에서 갈 수 있는 주유소들을 힙에 추가한다.
    # 현재의 위치는 즉 연료의 양안에 들어야 그 주유소에 갈 수 있다.
    while idx < n and arr[idx][0] <= now:
        heapq.heappush(q, -arr[idx][1])
        idx += 1
        # 최대 힙을 사용해서 내림차순으로 하기 위해 -로 넣는다.

    # 진행하는 동안에 주유소가 없다면 못가므로 -1을 출력한다.
    if not q:
        ans = -1
        break

    # 갈 수 있는 주유소들 중
    # 가장 큰 연료를 제공하는 주유소에서 연료를 보충한다.
    now += -heapq.heappop(q)
    ans += 1

print(ans)