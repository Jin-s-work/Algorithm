from collections import deque

def solution(rectangle, characterX, characterY, itemX, itemY):
    answer = 0
    
    arr = [[-1] * 102 for _ in range(102)]
    
    # 좌표 간에 간격을 찾으려고 두배로 늘려서 찾는다.
    
    for i in range(len(rectangle)):
        startx, starty = rectangle[i][0] * 2, rectangle[i][1] * 2
        endx, endy = rectangle[i][2] * 2, rectangle[i][3] * 2
        
        for a in range(startx, endx+1):
            for b in range(starty, endy+1):
                if startx < a < endx and starty < b < endy:
                    arr[a][b] = 0
                elif arr[a][b] != 0:
                    arr[a][b] = 1
    
    check = [[1] * 102 for _ in range(102)]
    dx = [0,0,1,-1]
    dy = [1,-1,0,0]
    
    q = deque()
    q.append([characterX * 2, characterY * 2])
    check[characterX * 2][characterY * 2] = 0
    

    while q:
        x, y = q.popleft()
        
        if x == itemX * 2 and y == itemY * 2:
            answer = check[x][y] // 2
            break
        # 두배로 늘렸으므로 좌표도 2배씩

        for i in range(4):
            nx = x + dx[i]
            ny = y + dy[i]

            if check[nx][ny] == 1 and arr[nx][ny] == 1:
                q.append([nx, ny])
                check[nx][ny] = check[x][y] + 1    

    
    return answer