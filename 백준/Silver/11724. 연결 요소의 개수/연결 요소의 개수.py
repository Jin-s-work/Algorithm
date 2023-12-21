import sys
sys.setrecursionlimit(10**6)
input = sys.stdin.readline


from collections import deque


def DFS(start):
    check[start] = True
    for i in arr[start]:
        if not check[i]:
            DFS(i)
    # arr[v]를 i로 하고 arr[v]가 아직 false일 때 DFS로 들어간다.

n, m = map(int, input().split())
arr = [[] for _ in range(n+1)]
check = [0 for _ in range(n+1)]

for _ in range(m):
    a, b = map(int, input().split())
    arr[a].append(b)
    arr[b].append(a)
    
# check가 False인 곳에서 부터 시작해서
# DFS를 해줘서 들어가고 나올 때 1씩 더해주면 개수를 구할 수 있다.
ans = 0
for i in range(1, n+1):
    if not check[i]:
        DFS(i)
        ans += 1

print(ans)