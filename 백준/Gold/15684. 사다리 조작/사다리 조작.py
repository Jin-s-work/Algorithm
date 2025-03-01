

n, m, h = map(int, input().split())

ladder = [[0] * (n + 1) for _ in range(h + 1)]

# 사다리 게임을 조작해서 i번 세로선의 결과가 i번이 나와야 한다.
# 추가해야 하는 가로선 개수의 최솟값을 구해라
# 가로선은 3개까지만 추가가 가능하다. 넘으면 안되고 -1

for _ in range(m):
    a, b = map(int, input().split())
    ladder[a][b] = 1
    # b에서 b+1 세로선으로 이동
    ladder[a][b+1] = -1
    # b+1에서 b 세로선으로 이동

def valid():
    for start in range(1, n + 1):
        now = start
        for i in range(1, h + 1):
            if ladder[i][now] == 1:
                now += 1
            elif ladder[i][now] == -1:
                now -= 1

        if now != start:
            return False
    return True
# 사다리가 제대로 가고 있는지 찾는 함수
# 일단 먼저 (a, b)의 의미는 높이 a에서 b번 세로선과 b+1번 세로선이 연결되었다는 뜻이다.
# 따라서, b에서 b+1로 이동은 1로 b+1에서 b로 이동은 -1로 체크해준다.
# -> b+1의 상태에서 b로 오는 것이기에 ladder[a][b+1] = -1로 놓는게 맞다.

ans = 4
def DFS(cnt, x, y):
    global ans

    if valid():
        ans = min(ans, cnt)
        return

    if cnt >= 3:
        return

    # (x, y) 위치부터 가능한 모든 가로선의 위치에 대해 탐색
    for i in range(x, h + 1):
        for j in range(1, n):
            if ladder[i][j] == 0 and ladder[i][j+1] == 0:
                ladder[i][j] = 1
                ladder[i][j+1] = -1

                DFS(cnt + 1, i, j + 2)
                # 같은 행에서는 연속된 가로선을 방지하기 위해서 j+2부터 탐색한다.
                # 왜냐하면 같은 높이에서 b-b+1이 연결되어있으면, b+1과 b+2는 연결될 수 없다

                ladder[i][j] = 0
                ladder[i][j+1] = 0

DFS(0, 1, 1)

if ans <= 3:
    print(ans)
else:
    print(-1)



