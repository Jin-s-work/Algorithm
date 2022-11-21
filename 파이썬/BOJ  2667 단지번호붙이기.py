from collections import deque
n = int(input())

dx = [0,0,1,-1]
dy = [1,-1,0,0]

arr = []
for _ in range(n):
    arr.append(list(map(int, input())))
# check = [[False] for _ in range(n+1)]

def BFS(a, b):
    cnt = 1
    # 처음것도 포함해야 하므로 1부터 시작
    queue = deque()
    queue.append((a, b))
    arr[a][b] = 0
    while queue:
        x, y = queue.popleft()
        for i in range(4):
            nx = x + dx[i]
            ny = y + dy[i]
            
            if nx < 0 or nx >= n or ny < 0 or ny >= n:
                continue
            
            if arr[nx][ny] == 1:
                arr[nx][ny] = 0
                # 지난 arr를 0으로 그냥 바꾸어서 지나감을 표시하는게 편리
                cnt += 1
                queue.append((nx, ny))
                # append 해줄때 괄호에 신경쓰기!
    return cnt

answer = []
for i in range(n):
    for j in range(n):
        if arr[i][j] == 1:
            answer.append(BFS(i, j))

answer.sort()
print(len(answer))
for k in answer:
    print(k)

