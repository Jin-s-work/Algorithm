
from collections import deque

def solution(maps):
    answer = 0
    
    dx = [0,0,1,-1]
    dy = [1,-1,0,0]
    
    n = len(maps)
    m = len(maps[0])
    
    q = deque()
    # check = [[0] * (m + 1) for _ in range(n + 1)]
    q.append((0,0))
    
    while q:
        x, y = q.popleft()
        
        for i in range(4):
            nx = x + dx[i]
            ny = y + dy[i]
            if 0<=nx<n and 0<=ny<m and maps[nx][ny] == 1:
                maps[nx][ny] = maps[x][y] + 1
                q.append((nx, ny))
    
    if maps[n-1][m-1] == 0 or maps[n-1][m-1] == 1:
        return -1
    else:
        return maps[n-1][m-1]