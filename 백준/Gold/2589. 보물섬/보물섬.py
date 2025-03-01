
from collections import deque

n, m = map(int, input().split())

arr = []
for i in range(n):
    tmp = input()
    arr.append(tmp)

# 보물은 육지에 저장되어있고, 이동은 육지로만 가능하다.
# 보물은 서로 간에 가장 긴 시간이 걸리는 육지 두 곳에 나뉘어져 있다.

ans = 0

land = []
for i in range(n):
    for j in range(m):
        if arr[i][j] == 'L':
            land.append((i, j))

dx = [0,0,1,-1]
dy = [1,-1,0,0]

for land_x, land_y in land:
    q = deque()
    q.append((land_x, land_y))
    check = [[0] * (m + 1) for _ in range(n+1)]
    check[land_x][land_y] = 1

    while q:
        x, y = q.popleft()
        for i in range(4):
            nx = x + dx[i]
            ny = y + dy[i]
            if 0<=nx<n and 0<=ny<m and arr[nx][ny] == 'L' and not check[nx][ny]:
                check[nx][ny] = check[x][y] + 1
                q.append((nx, ny))

    for i in range(n):
        for j in range(m):
            ans = max(ans, check[i][j])

print(ans - 1)



