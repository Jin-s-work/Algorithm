import sys
sys.setrecursionlimit(10**6)
input = sys.stdin.readline


from collections import deque

n, m = map(int, input().split())

arr = [[] for _ in range(n+1)]
for _ in range(m):
    a, b = map(int, input().split())
    arr[a].append(b)
    arr[b].append(a)
    
check = [0] * (n+1)
def BFS(start):
    q = deque([start])
    check[start] = 1
    
    while q:
        num = q.popleft()
        for k in arr[num]:
            if check[k] == 0:
                check[k] = check[num] + 1
                q.append(k)

BFS(1)

k = max(check)

print(check.index(k), k-1, check.count(k))

# ans = 0
# cnt = 0
# dist = -1
# for i in range(1, len(check)):
#     if check[i] > dist:
#         dist = check[i]
#         ans = i
#     elif check[i] == dist:
#         cnt += 1

# print(ans, dist-1, cnt)

