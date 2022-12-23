import sys
n = int(input())
arr = []
for _ in range(n):
    arr.append(list(map(int, input().split())))
ans = sys.maxsize
check = [0] * n

def DFS(start, now, cost, num):
    global ans
    if num == n:
        if arr[now][start]:  # 아직 방문하지 않을 경우
            cost += arr[now][start]
            if ans > cost:   # ans가 더 클 경우 작게
                ans = cost
        return   # 그러고 리턴시켜 나가준다.
    
    # cost가 ans보다 커질 경우 min이 아닐 경우 리턴한다.
    if cost > ans:
        return
    
    for i in range(n):
        if not check[i] and arr[now][i]:
            check[i] = 1
            DFS(start, i, cost + arr[now][i], num+1)
            check[i] = 0

for i in range(n):
    check[i] = 1
    DFS(i, i, 0, 1)
    check[i] = 0
print(ans)
