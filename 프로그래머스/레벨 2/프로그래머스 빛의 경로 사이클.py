def solution(grid):
    answer = []
    
    dx = (1,0,-1,0)
    dy = (0,-1,0,1)
    
    n = len(grid)
    m = len(grid[0])
    
    # x * y * 4 를 방문기록 리스트 만듬 [x][y][4]
    check = [[[False] * 4 for _ in range(m)] for _ in range(n)]
    
    for x in range(n):
        for y in range(m):
            for d in range(4):
                # 해당 방향이 이미 사용되어 true인 경우는 continue
                if check[x][y][d]:
                    continue
                
                # 사용되지 않은 방향의 경우
                cnt = 0
                nx = x
                ny = y
                
                # 방문되지 않을 경우
                while not check[nx][ny][d]:
                    check[nx][ny][d] = True  # 방문 표시를 하고
                    cnt += 1
                    if grid[nx][ny] == "S":  # S인 경우는 변경 x
                        pass
                    elif grid[nx][ny] == "L": # L인 경우 반시계 방향
                        d = (d - 1) % 4
                    elif grid[nx][ny] == "R": # R인 경우 시계 방향
                        d = (d + 1) % 4
                        
                    # n이나 m과 같은 격자를 벗어난 경우에도 잘 찾아가게
                    # 나머지를 사용한다.
                    nx = (nx + dx[d]) % n
                    ny = (ny + dy[d]) % m
                
                answer.append(cnt)
    
    answer = sorted(answer)
    
    return answer
