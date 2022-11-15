from collections import deque
dx = [-1,1,0,0]
dy = [0,0,-1,1]

def BFS(p):
    start = []
    for i in range(5):
        for j in range(5):
            if p[i][j] == 'P':
                start.append([i, j])
    
    for s in start:
        queue = deque([s]) # 큐에 초기값 넣어주기
        check = [[0] * 5 for i in range(5)]
        distance = [[0] * 5 for i in range(5)]
        check[s[0]][s[1]] = 1
        
        while queue:
            x, y = queue.popleft()
            for i in range(4):
                nx = x + dx[i]
                ny = y + dy[i]
                
                if nx < 0 or nx >= 5 or ny < 0 or ny >= 5 or check[nx][ny] != 0:
                    continue
                if p[nx][ny] == 'O':
                    queue.append([nx, ny])
                    check[nx][ny] = 1
                    distance[nx][ny] = distance[x][y] + 1
                # 빈 테이블일 경우 이동이 가능하므로 check를 표시하고 distance를 늘려준다.
                    
                if p[nx][ny] == 'P' and distance[x][y] <= 1:
                    return 0
                # 만약 P를 만났는데 x,y의 distance가 1보다 작을 경우 안되므로 0을 리턴
    return 1



def solution(places):
    answer = []
    
    # 맨해튼 거리가 2이하는 앉지 말기
    # 앉아있는 자리 사이에 파티션이 있을 경우는 허용
    # P는 응시자가 앉은 자리
    # O는 빈 테이블, X는 파티션
    
    for i in places:
        answer.append(BFS(i))
    
    
    
    return answer
