
from collections import deque

def solution(board, h, w):
    answer = 0
    
    n = len(board)
    check = [[0] * n for _ in range(n)]
    
    dx = [0,0,1,-1]
    dy = [1,-1,0,0]
    
    def isin(a, b):
        return 0<=a<n and 0<=b<n
    
    q = deque()
    q.append((h, w))
    while q:
        x, y = q.popleft()
        for i in range(4):
            nx = x + dx[i]
            ny = y + dy[i]
            
            if isin(nx, ny) and board[nx][ny] == board[x][y] and check[nx][ny] == 0:
                check[nx][ny] = 1
                answer += 1
    
    
    
    
    return answer