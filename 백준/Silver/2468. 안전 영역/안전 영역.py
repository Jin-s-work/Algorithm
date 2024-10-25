
import sys
sys.setrecursionlimit(10000) 
n = int(input())

Max = 0
arr = []
for i in range(n):
    tmp = list(map(int, input().split()))
    Max = max(Max, max(tmp))
    arr.append(tmp)

dx = [0,0,1,-1]
dy = [1,-1,0,0]
def DFS(a, b):
    check[a][b] = True
    for i in range(4):
        nx = a + dx[i]
        ny = b + dy[i]
        if 0<=nx<n and 0<=ny<n and not check[nx][ny] and arr[nx][ny] > k:
            DFS(nx, ny)


ans = 0
for k in range(Max + 1):
    check = [[0] * (n + 1) for _ in range(n + 1)]
    num = 0

    for i in range(n):
        for j in range(n):
            if not check[i][j] and arr[i][j] > k:
                DFS(i, j)
                num += 1

    ans = max(num, ans)

print(ans)