
import sys
sys.setrecursionlimit(100000)

n = int(input())

arr = [[] for _ in range(n + 1)]

for _ in range(n-1):
    l, r, num = map(int, input().split())

    arr[l].append((r, num))
    arr[r].append((l, num))


ans = 0
def DFS(node, dist):
    check[node] = True
    for next, weight in arr[node]:
        if not check[next]:
            DFS(next, dist + weight)

    global max_dist, farthest
    if dist > max_dist:
        max_dist = dist
        farthest = node

check = [0] * (n + 1)
max_dist = 0
farthest = 1

# 루트 1에서 가장 먼 노드 찾기
DFS(1, 0)

# 그 노드에서 다시 DFS -> 지름 구하기
check = [0] * (n + 1)
max_dist = 0
DFS(farthest, 0)

print(max_dist)
