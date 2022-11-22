
import sys
sys.setrecursionlimit(300000)

def DFS(v):
    for i in arr[v]:
        if not check[i]:
            check[i] = check[v] + 1
            DFS(i)
    # 들어갈 수 있는 경우 check를 그냥 증가시켜 주면서 DFS를 들어감
        
n = int(input())
a, b = map(int, input().split())
m = int(input())

arr = [[] for _ in range(n+1)]
check = [0] * (n+1)
for _ in range(m):
    c, d = map(int, input().split())
    arr[c].append(d)
    arr[d].append(c)

DFS(a)

if check[b] > 0:
    print(check[b])
else:
    print(-1)
