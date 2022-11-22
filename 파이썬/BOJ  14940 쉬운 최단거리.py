from collections import deque
n, m = map(int, input().split())

dx = [0,0,1,-1]
dy = [1,-1,0,0]

arr = []
for _ in range(n):
    arr.append(list(map(int, input().split())))

check = [[False] * m for _ in range(n)]
ans = [[-1] * m for _ in range(n)]
    


queue = deque()
# deque에 바로 넣어주면 에러가 자주 나는 거 같으니 그냥 새로 하고
# append로 처음 값을 넣어주자

start_x, start_y = 0,0
for i in range(n):
    for j in range(m):
        if arr[i][j] == 2:
            queue.append([i, j])
            check[i][j] = True
            ans[i][j] = 0
        elif arr[i][j] == 0:
            ans[i][j] = 0
            


while queue:
    x, y = queue.popleft()
    for i in range(4):
        nx = x + dx[i]
        ny = y + dy[i]
        
        if nx < 0 or nx >= n or ny < 0 or ny >= m:
            continue
        
        if check[nx][ny] == False and arr[nx][ny] == 1:
            check[nx][ny] = True
            queue.append([nx, ny])
            ans[nx][ny] = ans[x][y] + 1
        
# check를 안하면 중복이 될 수 있으므로 check를 해야한다.
# 이게 안돼서 10분 정도 더 걸림


for i in range(n):
    for j in range(m):
        print(ans[i][j], end = " ")
    print()
    
