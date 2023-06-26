
from collections import deque

# n, m = map(int, input().split())
# arr = []
# for i in range(n):
#     arr.append(list(map(int, input())))
    
# dx = [0,0,1,-1]
# dy = [1,-1,0,0]

# def BFS(x, y):
#     queue = deque()
#     queue.append((x, y))
    
#     while queue:
#         x, y = queue.popleft()
#         for i in range(4):
#             nx = x + dx[i]
#             ny = y + dy[i]
#             if nx < 0 or nx >= n or ny < 0 ny >= m:
#                 continue
            
#             if arr[nx][ny] == 0:
#                 continue
                
#             if arr[nx][ny] == 1:
#                 arr[nx][ny] = arr[x][y] + 1
#                 queue.append((nx, ny))
                
#     return arr[n-1][m-1]
    
    

def solution(maps):
    answer = 0
    lever = False
    
    check = [[0] * len(maps[0]) for _ in range(len(maps))]
    
    for i in range(len(maps)):
        for j in range(len(maps[0])):
            if maps[i][j] == 'S':
                start = (i, j)
                check[i][j] = 1
                break
                
    queue = deque()
    queue.append((start[0], start[1]))
    
    dx = [0,0,1,-1]
    dy = [1,-1,0,0]
    
    while queue:
        x, y = queue.popleft()
        if maps[x][y] == 'L' and not lever:
            answer += check[x][y]
            lever = True
            check = [[0] * len(maps[0]) for _ in range(len(maps))]
            check[x][y] = 1
            queue = deque()
            queue.append((x, y))
            continue
            
        if maps[x][y] == 'E' and lever:
            answer += check[x][y]
            return answer - 2
        
        for i in range(4):
            nx = x + dx[i]
            ny = y + dy[i]
            
            if nx in range(len(maps)) and ny in range(len(maps[0])):
                if not check[nx][ny] and maps[nx][ny] != 'X':
                    check[nx][ny] = check[x][y] + 1
                    queue.append((nx, ny))
                    
    
    answer = -1
    
    return answer