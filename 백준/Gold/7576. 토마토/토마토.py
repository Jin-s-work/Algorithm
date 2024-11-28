
from collections import deque
m, n = map(int, input().split())

arr = []
for i in range(n):
    tmp = list(map(int, input().split()))
    arr.append(tmp)

dx = [0,0,1,-1]
dy = [1,-1,0,0]

# 익은게 1, 안익은게 0, 토마토x -1

q = deque()
for i in range(n):
    for j in range(m):
        if arr[i][j] == 1:
            q.append((i, j))


ans = 0
while q:
    x, y = q.popleft()

    for i in range(4):
        nx = x + dx[i]
        ny = y + dy[i]

        # 다음 공간이 빈 공간 일 겨웅에만 넘어갈때 1씩 더해준다.
        # 그러면 끝까지 갔을때 제일 큰 숫자가 제일 오래걸린 시간이다.
        if 0<=nx<n and 0<=ny<m and arr[nx][ny] == 0:
            arr[nx][ny] = arr[x][y] + 1
            q.append((nx, ny))


for row in arr:
    if 0 in row:
        print(-1)
        exit()
    ans = max(ans, max(row))

print(ans - 1)
# 처음 1부터 시작이니까 1 줄여야 한다.
