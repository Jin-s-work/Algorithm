
from itertools import combinations
from collections import deque
import copy

n, m = map(int, input().split())

arr = []
for i in range(n):
    tmp = list(map(int, input().split()))
    arr.append(tmp)

# 벽을 3개 세워서 안전 영역 크기를 최대한으로

zero = []
virus = []
for i in range(n):
    for j in range(m):
        if arr[i][j] == 2:
            virus.append((i, j))
        elif arr[i][j] == 0:
            zero.append((i, j))

dx = [0,0,1,-1]
dy = [1,-1,0,0]

def spread_virus(tmp_arr):
    q = deque(virus)

    while q:
        x, y = q.popleft()

        for i in range(4):
            nx = x + dx[i]
            ny = y + dy[i]

            if 0<=nx<n and 0<=ny<m and tmp_arr[nx][ny] == 0:
                tmp_arr[nx][ny] = 2
                q.append((nx, ny))

    num = 0
    for i in range(n):
        for j in range(m):
           if tmp_arr[i][j] == 0:
               num += 1

    return num


ans = 0
for wall in combinations(zero, 3):
    tmp_arr = copy.deepcopy(arr)
    # 원본 배열을 변화만 없이 복사해서 사용한다.

    for x, y in wall:
        tmp_arr[x][y] = 1

    safe = spread_virus(tmp_arr)
    ans = max(ans, safe)

print(ans)
