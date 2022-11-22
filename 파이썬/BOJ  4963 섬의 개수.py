from collections import deque
import sys
input = sys.stdin.readline

dx = [0,0,1,1,1,-1,-1,-1]
dy = [1,-1,0,1,-1,0,1,-1]

def BFS(a, b):
    arr[a][b] = 0
    queue = deque()
    queue.append([a, b])
    
    while queue:
        x, y = queue.popleft()
        for i in range(8):
            nx = x + dx[i]
            ny = y + dy[i]
            if nx < 0 or nx >= m or ny < 0 or ny >= n:
                continue
            if arr[nx][ny] == 1:
                arr[nx][ny] = 0
                queue.append([nx, ny])

while True:
    n, m = map(int, input().split())
    if n == 0 and m == 0:
        break
        
    arr = []
    for _ in range(m):
        arr.append(list(map(int, input().split())))
    

    ans = 0
    for i in range(m):
        for j in range(n):
            if arr[i][j] == 1:
                BFS(i, j)
                ans += 1
    # 1일 경우 다 0으로 만들어 그냥 1의 개수를 세주는 것
    # 내 풀이와 거의 같은 메카니즘
    
    # 내 풀이도 맞는데 맨 밑에서 m,n 차이가 그냥 틀려서 틀린듯 ㅠ
    
    print(ans)
