
from itertools import combinations

arr = []
for i in range(5):
    tmp = list(input())
    arr.append(tmp)

# 7명의 학생
# 가로나 세로로 인접해야 함
# 반드시 '이다솜파'로 구성될 필요는 없다
# 7명 중 적어도 4명 이상은 있어야 한다.
# 즉 S가 최소 4명

grid = [(i, j) for i in range(5) for j in range(5)]
comb = list(combinations(grid, 7))

dx = [0,0,1,-1]
dy = [1,-1,0,0]

# 7개가 모두 연결되었는지를 check하는 BFS
def BFS(p):
    check = [[0] * 5 for _ in range(5)]
    st = [p[0]]
    check[p[0][0]][p[0][1]] = True
    cnt = 1

    while st:
        x, y = st.pop()
        for i in range(4):
            nx = x + dx[i]
            ny = y + dy[i]
            if (nx, ny) in p and not check[nx][ny]:
                check[nx][ny] = True
                st.append((nx, ny))
                cnt += 1
                if cnt == 7:
                    return True

    return False if cnt < 7 else True

# BFS를 작성하였으니 그냥 모든 경우에 대해서 4를 넘는지, 모두 다 이어져있는지만 check
# combination을 통하여 모든 경우의 수를 만들었으니 DFS는 없어도 된다.
# BFS 측에서 연결되지 않으면 빠져나오기 때문
ans = 0
for k in comb:
    s = 0
    for i in range(7):
        if arr[k[i][0]][k[i][1]] == 'S':
            s += 1

    if s >= 4 and BFS(k):
        ans += 1

print(ans)
