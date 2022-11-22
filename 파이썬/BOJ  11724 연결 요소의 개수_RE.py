import sys
sys.setrecursionlimit(10**6)
input = sys.stdin.readline

n, m = map(int, input().split())
arr = [[] for _ in range(n+1)]
check = [0] * (n+1)

def DFS(v):
    check[v] = True
    for i in arr[v]:
        if not check[i]:
            DFS(i)
    # 어차피 DFS 들어가서 바로 check를 True로 하므로 안해도 됨

for _ in range(m):
    a, b = map(int, input().split())
    arr[a].append(b)
    arr[b].append(a)
    
ans = 0

for i in range(1, n+1):
    if not check[i]:
        DFS(i)
        ans += 1
print(ans)

