from collections import deque
import sys
input = sys.stdin.readline
# 백준을 풀때는 이것을 거의 해줘야한다.

n, m, k, x = map(int, input().split())

arr = [[] for _ in range(n+1)]
check = [-1] * (n+1)
# 0으로 하면은 제대로 방문 확인이 안되므로 -1로 해준 다음에
# 지나가는 부분들을 다 따로 처리 해주어야 한다.
ans = []
for _ in range(m):
    a, b = map(int, input().split())
    arr[a].append(b)

queue = deque()
queue.append(x)
check[x] = 0
while queue:
    now = queue.popleft()
    for i in arr[now]:
        if check[i] == -1:
            check[i] = check[now] + 1
            queue.append(i)

flag = False
for i in range(len(check)):
    if check[i] == k:
        ans.append(i)
        flag = True
        # 위에서 그냥 인덱스에 맞게 들어오므로 고려 안해주고 그대로 출력해도 됨
ans.sort()
if flag:
    for t in ans:
        print(t)
else:
    print(-1)

