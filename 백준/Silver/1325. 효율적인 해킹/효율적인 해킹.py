import sys
# sys.setrecursionlimit(10**6)
input = sys.stdin.readline


from collections import deque

n, m = map(int, input().split())

arr = [[] for _ in range(n+1)]
for _ in range(m):
    a, b = map(int, input().split())
    # arr[a].append(b)
    arr[b].append(a)
    
def BFS(start):
    cnt = 1
    q = deque([start])
    check = [0 for _ in range(n+1)]
    check[start] = 1
    
    while q:
        num = q.popleft()
        for k in arr[num]:
            if check[k] == 0:
                check[k] = 1
                q.append(k)
                cnt += 1
                
    return cnt
    
answer = []
Max = 0
for i in range(1, n+1):
    cnt = BFS(i)
    # cnt = sum(check) - 1
    if Max < cnt:
        Max = cnt
    answer.append([i, cnt])
    # elif cnt == Max:
    #     answer.append(i)

for a, b in answer:
    if b == Max:
        print(a, end = ' ')
    
    
    
