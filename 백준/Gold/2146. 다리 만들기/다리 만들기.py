
from collections import deque

n = int(input())

arr = []
for _ in range(n):
    tmp = list(map(int, input().split()))
    arr.append(tmp)

dx = [0,0,1,-1]
dy = [1,-1,0,0]

def island_num():
    island_id = 2
    for i in range(n):
        for j in range(n):
            if arr[i][j] == 1:
                q = deque([(i, j)])
                arr[i][j] = island_id
                while q:
                    x, y = q.popleft()
                    for dir in range(4):
                        nx = x + dx[dir]
                        ny = y + dy[dir]
                        if 0<=nx<n and 0<=ny<n and arr[nx][ny] == 1:
                            arr[nx][ny] = island_id
                            q.append((nx, ny))
                island_id += 1
                # 이렇게 대륙의 넘버를 증가시키면서 대륙들을 구별해준다.

def find_short():
    def BFS(start, island_id):
        check = [[-1] * n for _ in range(n)]
        q = deque(start)

        for x, y in start:
            check[x][y] = 0

        while q:
            x, y = q.popleft()
            for i in range(4):
                nx = x + dx[i]
                ny = y + dy[i]
                if 0<=nx<n and 0<=ny<n:
                    if arr[nx][ny] != island_id and arr[nx][ny] > 0:
                        return check[x][y]
                # 다른 섬에 도달한 것이다.

                    if arr[nx][ny] == 0 and check[nx][ny] == -1:
                        check[nx][ny] = check[x][y] + 1
                        q.append((nx, ny))
        return float('inf')

    short = float('inf')
    for island_id in range(2, max(map(max, arr)) + 1):
        start = []
        for x in range(n):
            for y in range(n):
                if arr[x][y] == island_id:
                    for i in range(4):
                        nx = x + dx[i]
                        ny = y + dy[i]
                        if 0<=nx<n and 0<=ny<n and arr[nx][ny] == 0:
                            start.append((x, y))
                            break
        short = min(short, BFS(start, island_id))
    return short

island_num()
print(find_short())
