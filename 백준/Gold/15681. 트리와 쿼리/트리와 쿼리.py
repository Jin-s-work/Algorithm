import sys
sys.setrecursionlimit(1000000)
input = sys.stdin.readline

n, r, q = map(int, input().split())
# 정점의 수, 루트 번호, 쿼리의

arr = [[] for _ in range(n + 1)]
for _ in range(n-1):
    a, b = map(int, input().split())
    arr[a].append(b)
    arr[b].append(a)
# 트리에 속한 간선의 정

graph = [0] * (n + 1)

# R에서 DFS를 돌리면 자기 자신 + 자식들 서브트리 크기 구할 수 있다.
# 먼저 graph[u] = 1 -> 자기 자신
# v가 부모가 아니면 DFS
# 리턴하면 sub[u]에 서브트리 크기가 완성 계속 더해주기에,,

def DFS(u, parent):
    graph[u] = 1
    for v in arr[u]:
        if v == parent:
            continue
        DFS(v, u)
        # u를 parent로 해서 DFS로 들어가준다.
        graph[u] += graph[v]

DFS(r, 0)

# 서브트리에 속한 정점의 수를 출력
for _ in range(q):
    a = int(input())
    print(graph[a])

