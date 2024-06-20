import sys 
sys.setrecursionlimit(10000)

def solution(maps):
    answer = []
    
    dx = [0,0,1,-1]
    dy = [1,-1,0,0]
    
    n, m = len(maps), len(maps[0])
    
    check = [[False] * (m) for _ in range(n)]

    def DFS(x, y):
        num = int(maps[x][y])
        check[x][y] = True
        for i in range(4):
            nx = x + dx[i]
            ny = y + dy[i]
            
            if 0<=nx<n and 0<=ny<m and not check[nx][ny] and maps[nx][ny] != 'X':
                check[nx][ny] = True
                num += DFS(nx, ny)      
        
        return num
    
    for i in range(n):
        for j in range(m):
            if maps[i][j] != "X" and not check[i][j]:
                answer.append(DFS(i, j))
    
    if len(answer) == 0:
        return [-1]
    
    answer.sort()
    
    return answer