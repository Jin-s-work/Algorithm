
from itertools import combinations
from collections import deque
n, m = map(int, input().split())

arr = []
for i in range(n):
    tmp = list(map(int, input().split()))
    arr.append(tmp)

# 바이러스 m개를 활성 상태로 변경
# 0은 빈칸, 1은 벽, 2는 바이러스

def BFS(virus):
    q = deque(virus)
    check = [[-1] * n for _ in range(n)]
    for x, y in virus:
        check[x][y] = 0

    Max = 0
    empty = total
    # empty의 개수를 total로 해주고 빈칸 지날때마다 빼주

    while q:
        x, y = q.popleft()
        for i in range(4):
            nx = x + dx[i]
            ny = y + dy[i]
            if 0 <= nx < n and 0 <= ny < n and check[nx][ny] == -1:
                if arr[nx][ny] == 0:
                    check[nx][ny] = check[x][y] + 1
                    q.append((nx, ny))
                    Max = max(Max, check[nx][ny])
                    empty -= 1
                elif arr[nx][ny] == 2:
                    check[nx][ny] = check[x][y] + 1
                    q.append((nx, ny))

    return Max if empty == 0 else float('inf')

dx = [0,0,1,-1]
dy = [1,-1,0,0]

total = 0
virus_pos = []
for i in range(n):
    for j in range(n):
        if arr[i][j] == 2:
            virus_pos.append((i, j))
        elif arr[i][j] == 0:
            total += 1
# 2일 경우 바이러스에 넣어주고
# 0일 경우에 empty로 헤준다.

if total == 0:
    print(0)
    exit(0)

# virus에 대해서 combination으로 해서 virus에 넣어서 리스트로 BFS에 넣어서 리
Min = float('inf')
for virus in combinations(virus_pos, m):
    t = BFS(virus)
    Min = min(Min, t)

print(Min if Min != float('inf') else -1)


