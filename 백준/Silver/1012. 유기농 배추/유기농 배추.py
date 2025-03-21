
from  collections import deque
t = int(input())

dx = [0, 0, 1, -1]
dy = [1, -1, 0, 0]


def BFS(x, y):
    q = deque()
    q.append((x, y))
    check[x][y] = True

    while q:
        x, y = q.popleft()

        for i in range(4):
            nx = x + dx[i]
            ny = y + dy[i]

            if 0 <= nx < n and 0 <= ny < m:
                if not check[nx][ny] and arr[x][y] == 1:
                    check[nx][ny] = True
                    q.append((nx, ny))

for _ in range(t):
    m, n, k = map(int, input().split())

    arr = [[0] * (m + 1) for _ in range(n + 1)]
    check = [[0] * (m + 1) for _ in range(n + 1)]

    for _ in range(k):
        x, y = map(int, input().split())
        arr[y][x] = 1

    ans = 0
    for i in range(n):
        for j in range(m):
            if arr[i][j] == 1 and not check[i][j]:
                BFS(i, j)
                ans += 1
    # 배추가 있고 아직 방문하지 않은 경우 BFS로 들어간다.
    # 배추가 있어도 이미 방문할 경우 섬의 수로 세운다.

    print(ans)

