from collections import deque
n, m = map(int, input().split())

arr = []
for _ in range(n):
    arr.append(list(map(int, input())))
# n줄에 list로 만들어서 arr에 각각 넣어줌

dx = [-1,1,0,0]
dy = [0,0,-1,1]

queue = deque()
queue.append([0,0])
while queue:
    x, y = queue.popleft()
    for i in range(4):
        nx = x + dx[i]
        ny = y + dy[i]
        
        if nx < 0 or nx >= n or ny < 0 or ny >= m:
            continue
        if arr[nx][ny] == 0:
            continue
        
        if arr[nx][ny] == 1:
            arr[nx][ny] = arr[x][y] + 1
            # 이런식으로 그냥 1씩 늘려주면 방문 확인 안해도댐
            queue.append([nx, ny])
            
print(arr[n-1][m-1])
