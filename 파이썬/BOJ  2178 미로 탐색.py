from collections import deque
# python에서 queue와 비슷한 deque를 쓰기 위하여

n, m = map(int, input().split())
# map은 여기서 n,m에 대해 모두 int로 해준다는 뜻

arr = []
for _ in range(n):
    arr.append(list(map(int, input())))
# 리스트 형태로 n줄을 arr에 넣어준다.

dx = [1,-1,0,0]
dy = [0,0,-1,1]
               
def BFS(a, b):
    # queue에 deque로 새로 큐를 만들어준다.
    queue = deque()
    queue.append((a, b))
    # 처음에 들어가는 a,b를 append해준다.
    
    while queue:
        x, y = queue.popleft()
        # 두개의 값이 나온다.
               
        for i in range(4):
            nx = x + dx[i]
            ny = y + dy[i]
        
            if nx < 0 or nx >= n or ny < 0 or ny >= m:
                continue
            if arr[nx][ny] == 0:
                continue
            if arr[nx][ny] == 1:
                arr[nx][ny] = arr[x][y] + 1
                queue.append((nx, ny))
                
    return arr[n-1][m-1]
               
print(BFS(0,0))
