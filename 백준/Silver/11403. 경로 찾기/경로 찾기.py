import sys
sys.setrecursionlimit(10**6)
input = sys.stdin.readline


from collections import deque

n = int(input())

# 한 줄씩 arr로 받아서 한줄 씩 list로 넣는다.
graph = [[] for _ in range(n)]
for i in range(n):
    arr = list(map(int, input().split()))
    for j in range(n):
        if arr[j] == 1:
            graph[i].append(j)
            # 그 중에서 1인게 나오면 graph에 넣는다.

def BFS(a):
    check = [0] * (n)
    q = deque([a])
    # 여기서는 간선이 존재하는 것을 보는 것이므로 자기 자신이라도 0일 수 있다.
    
    while q:
        num = q.popleft()
        for k in graph[num]:
            if check[k] == 0:
                check[k] = 1
                q.append(k)
    
    print(*check)
    # 줄마다 거기의 check를 출력하면 그 한 줄이 출력된다.
    
for i in range(n):
    BFS(i)
    

