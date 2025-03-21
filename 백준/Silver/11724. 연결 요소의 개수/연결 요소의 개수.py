

n, m = map(int, input().split())

arr = [[] for _ in range(n + 1)]
for _ in range(m):
    a, b = map(int, input().split())
    arr[a].append(b)
    arr[b].append(a)

check = [0] * (n + 1)
ans = 0

def DFS(num):
    check[num] = True
    for next in arr[num]:
        if not check[next]:
            DFS(next)
    # num을 방문표시해주고, 다음으로 넘어가는게 아직 False일 경우 들어간다.

for i in range(1, n + 1):
    if not check[i]:
        DFS(i)
        ans += 1
    # 아직 체크되지 않았으면 DFS해주고, ans 늘려준다.

print(ans)