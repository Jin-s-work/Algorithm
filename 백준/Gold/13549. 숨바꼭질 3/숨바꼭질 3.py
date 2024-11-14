
from collections import deque
n, k = map(int, input().split())

check = [-1] * 1000001
ans = 50000
check[n] = 0

if n == k:
    print(0)
    exit(0)

q = deque([n])
while q:
    now = q.popleft()
    if now == k:
        print(check[now])
        break

    # 시간을 제대로 확인하기 위해서 -1로 해놓고 n을 0부터 check에 시작하는게 좋다
    # 이동하는 부분을 확인하고 움직여야 하는데 지금 위치만 확인해서 움직이지 않았
    if now * 2 <= 1000000 and check[now * 2] == -1:
        check[now * 2] = check[now]
        q.appendleft(now * 2)
    # 순간이동은 왼쪽에 추가해서 우선적으로 처리한다.
    if now - 1 >= 0 and check[now - 1] == -1:
        check[now - 1] = check[now] + 1
        q.append(now - 1)
    if now + 1 <= 1000000 and check[now + 1] == -1:
        check[now + 1] = check[now] + 1
        q.append(now + 1)
    





