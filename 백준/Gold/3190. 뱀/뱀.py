

# 몸길이를 늘려 머리를 다음칸에 위치시킨다.
# 벽이나 자기자신의 몸과 부딪치면 게임 끝
# 이동한 칸에 사과가 있다면, 그 칸에 있던 사과가 없어지고 꼬리는 움직이지 않는다.
# 이동한 칸에 사과가 없다면, 몸길이를 줄여서 꼬리가 위치한 칸을 비워준다. 몸길이 변화 x

from collections import deque

n = int(input())
k = int(input())

arr = [[0] * (n) for _ in range(n)]

apple = []
for i in range(k):
    a, b = map(int, input().split())
    arr[a-1][b-1] = 1

change = deque()
l = int(input())
for i in range(l):
    x, c = map(str, input().split())
    change.append((int(x), c))
# x초가 끝난 뒤에 왼쪽 또는 오른족으로 회전시키는

t = 0
dir = 0
# 동 북  서  남
# 0  1  2  3
# 따라서 c가 L이면 +1 R이면 -1

dx = [0,-1,0,1]
dy = [1,0,-1,0]


snake = deque([(0,0)])

while True:

    t += 1
    head_x, head_y = snake[-1]
    # 뱀의 머리 위치
    nx = head_x + dx[dir]
    ny = head_y + dy[dir]

    if nx < 0 or nx >= n or ny < 0 or ny >= n or (nx, ny) in snake:
        break
    # 벽이나 자기 몸과 부딪치는 경우 종료

    if arr[nx][ny] == 1:
        arr[nx][ny] = 0
    else:
        snake.popleft()
    # 사과가 있을 경우 사과를 제거해준다.
    # 사과가 없을 경우 몸길이를 줄여 꼬리가 위치한 칸을 비워준다.

    snake.append((nx, ny))
    # 새로운 머리 위치 추가해준다.
    
    # change 안에 값들이 있고 그 맨 앞의 값(시간)이 t일 경우에 방향 바꾸기를 진행한다.
    # 특정시간이 맞을 경우에 진
    if change and change[0][0] == t:
        d, c = change.popleft()
        if c == 'L':
            dir = (dir + 1) % 4
        else:
            dir = (dir - 1) % 4

print(t)