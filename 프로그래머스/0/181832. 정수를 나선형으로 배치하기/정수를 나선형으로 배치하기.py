def solution(n):
    answer = [[]]
    
    answer = [[0] * n for _ in range(n)]
    dir = [(0, 1), (1, 0), (0, -1), (-1, 0)]
    
    x, y, d = 0, 0, 0
    for num in range(1, n*n+1):
        answer[x][y] = num
        dx, dy = dir[d]
        
        nx = x + dx
        ny = y + dy
        
        if nx < 0 or nx >= n or ny < 0 or ny >= n or answer[nx][ny] != 0:
            d = (d + 1) % 4
            dx, dy = dir[d]
            nx = x + dx
            ny = y + dy
        
        x, y = nx, ny
            
            
    
    
    return answer