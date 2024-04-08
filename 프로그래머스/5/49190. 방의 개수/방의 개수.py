def solution(arrows):
    answer = 0
    
    dy = [-1,-1,0,1,1,1,0,-1]
    dx = [0,1,1,1,0,-1,-1,-1]
    
    x, y = 0, 0
    edge = set()
    cord = set([(x, y)])
    
    for arrow in arrows:
        for _ in range(2):
            nx = x + dx[arrow]
            ny = y + dy[arrow]
            
            if (nx, ny) in cord and (x, y, nx, ny) not in edge:
                answer += 1
            
            cord.add((nx, ny))
            edge.add((x, y, nx, ny))
            edge.add((nx, ny, x, y))
            x = nx
            y = ny
            
    return answer

# 직접 좌표를 찍어서 풀면 100000이므로 시간 초과!
# 닫힌 공간이 되려면 방문했던 점을 다시 방문해야 한다. 
# 따라서, 다음의 좌표가 이미 cord에 있고, edge는 다를 경우 늘려준다.
# edge에는 오늘 선분 가는 선분 들다 넣는다.
# 그리고 옮겨진 좌표를 저장해준다.

