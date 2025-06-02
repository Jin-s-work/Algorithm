

n, east, west, south, north = map(int, input().split())

# 같은 곳을 한번보다 많이 이동하지 않을 때

move = [east / 100, west / 100, south / 100, north / 100]
check = [[0] * (2 * n + 1) for _ in range(2 * n + 1)]
dx = [0,0,1,-1]
dy = [1,-1,0,0]
total = 0

def DFS(x, y, cnt, prob):
    global total

    if cnt == n:
        total += prob
        return

    for i in range(4):
        nx = x + dx[i]
        ny = y + dy[i]

        if not check[nx][ny]:
            check[nx][ny] = True
            DFS(nx, ny, cnt + 1, prob * move[i])
            check[nx][ny] = False

check[n][n] = True
DFS(n, n, 0, 1)
# 시작점을 중앙으로 해서 양수 좌표를 유지한다.

print(f"{total:.9f}")

