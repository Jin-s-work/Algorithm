import sys
sys.setrecursionlimit(10**6)
input = sys.stdin.readline


from collections import deque

n = int(input())
m = int(input())

arr = [[] for _ in range(n+1)]
for _ in range(m):
    a, b = map(int, input().split())
    arr[a].append(b)
    arr[b].append(a)
    
# 상근이는 1
    
# check = [0] * (n+1)
check = [0 for _ in range(n+1)]

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
# 여기에서는 그냥 1을 넣어주고, 처음 시작하는 부분을 1로 놓으면서 시작
# 따라서 2,3이 결혼식에 올 수 있는 친구이다.
# 1인 상근이의 경우 무시하고 2부터 하면 된다.

ans = 0
for i in range(2,n+1):
    if check[i] <= 3 and check[i] != 0:
        ans += 1
    
print(ans)
        
