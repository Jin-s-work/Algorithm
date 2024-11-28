

from collections import deque
n, k = map(int, input().split())

check = [-1] * 100001
ans = [0] * 100001

q = deque([n])
check[n] = 0
ans[n] = 1

while q:
    now = q.popleft()

    for next in (now - 1, now + 1, now * 2):
        if 0<= next <= 100000:
            # 아직 방문하지 않은 경우
            if check[next] == -1:
                check[next] = check[now] + 1
                ans[next] = ans[now]
                q.append(next)

            # 방문을 이미 했고
            # 같은 시간에 도달한 경우
            elif check[next] == check[now] + 1:
                ans[next] += ans[now]

# ans는 경우의 수들을 체크한다.
# 같은 값이 있을 때 거기까지 오는 경우의 수들을 누적해서 더해준다.
# 아직 방문하지 않은 데 넘어가는 경우에는 ans를 같은 값으로 만든다.
print(check[k])
print(ans[k])