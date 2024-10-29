
from itertools import combinations
import copy
from collections import deque


n, m = map(int, input().split())

arr = []
for i in range(n):
    tmp = list(map(int, input().split()))
    arr.append(tmp)

empty = [(i, j) for i in range(n) for j in range(m) if arr[i][j] == 0]
virus = [(i, j) for i in range(n) for j in range(m) if arr[i][j] == 2]

dx = [0,0,1,-1]
dy = [1,-1,0,0]

# 바이러스 위치들을 q에 다 넣어주고 시작한다.
# arr이 0일 경우 들어가서 2로 바꾸고 계속 q를 진행한다.
def spread_virus(arr_map):
    q = deque(virus)
    while q:
        x, y = q.popleft()
        for i in range(4):
            nx = x + dx[i]
            ny = y + dy[i]
            if 0<=nx<n and 0<=ny<m and arr_map[nx][ny] == 0:
                arr_map[nx][ny] = 2
                q.append((nx, ny))

# 0인 구간을 세준다.
def count_safe(arr_map):
    return sum(row.count(0) for row in arr_map)

Max = 0
# 빈 공간들에 대해서 combination으로 3군데를 골라서 진행한다.
for wall in combinations(empty, 3):
    tmp_map = copy.deepcopy(arr)
    # arr를 바꾸지 않기 위해 deepcopy로 복제를 한 후에 진행한다.

    for x, y in wall:
        tmp_map[x][y] = 1
    # 3군데에 벽에 대해서 1로 표시한다.

    spread_virus(tmp_map)
    # 복사한 arr에 대해서 바이러스를 퍼트린 후에
    # safe를 세주고 갱신한다.
    safe = count_safe(tmp_map)
    Max = max(Max, safe)

print(Max)


