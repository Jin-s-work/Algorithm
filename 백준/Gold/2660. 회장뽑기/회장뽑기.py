import sys
sys.setrecursionlimit(10**6)
input = sys.stdin.readline


from collections import deque

n = int(input())

arr = [[] for _ in range(n+1)]
while True:
    a, b = map(int, input().split())
    
    if a == -1 and b == -1:
        break
    
    arr[a].append(b)
    arr[b].append(a)
    
    
def BFS(start):
    check = [-1] * (n+1)
    check[start] = 0
    q = deque([start])
    
    while q:
        num = q.popleft()
        for k in arr[num]:
            if check[k] == -1:
                check[k] = check[num] + 1
                q.append(k)
    # -1일 경우 아직 안 들어갔으므로 거기서 1씩 늘려주고 큐에 k를 넣어준다.
    
    return max(check)
    # 여기에서 최대로 증가한 check 부분을 출력해주면 된다.
    

# 최대 50개니까 깊이가 50을 넘을 수가 없다.
Min = 50
ans = []

for i in range(1, n+1):
    cnt = BFS(i)
    if cnt < Min:
        Min = cnt
        ans.clear()
        ans.append(i)
    elif cnt == Min:
        ans.append(i)

print(Min, len(ans))
print(*ans)
        
