import sys
sys.setrecursionlimit(10**6)
input = sys.stdin.readline


from collections import deque

k = int(input())

def BFS(start):
    q = deque([start])
    check[start] = 1
    
    while q:
        num = q.popleft()
        for k in arr[num]:
            if check[k] == 0:
                check[k] = -check[num]
                q.append(k)
            else:
                if check[k] == check[num]:
                    return False
    return True

for _ in range(k):
    v, e = map(int, input().split())
    arr = [[] for _ in range(v+1)]
    check = [0] * (v+1)
    flag = True
    for _ in range(e):
        a, b = map(int, input().split())
        arr[a].append(b)
        arr[b].append(a)
    
    for i in range(1, v+1):
        if check[i] == 0:
            if not BFS(i):
                flag = False
                break
    
    if flag:
        print("YES")
    else:
        print("NO")