


n = int(input())

arr = []
for i in range(n):
    tmp = list(map(int, input().split()))
    arr.append(tmp)

import sys
ans = sys.maxsize

check = [0] * (n + 1)
check[0] = 1

def DFS(start, now, cost, num):
    global ans

    if num == n:
        if arr[now][start] != 0:
            ans = min(ans, cost + arr[now][start])
        return

    # 계산하는 cost가 ans를 이미 넘을 경우 리턴한다.
    if cost >= ans:
        return

    for next in range(n):
        if arr[now][next] != 0 and not check[next]:
            check[next] = 1
            DFS(start, next, cost + arr[now][next], num + 1)
            check[next] = 0


# 시작점은 0, 지금 있는 곳도 0
# cost는 0, num도 1에서부터 시작한다. 한개이므로
DFS(0, 0, 0, 1)
print(ans)
