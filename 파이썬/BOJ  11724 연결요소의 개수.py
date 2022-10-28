import sys
sys.setrecursionlimit(10**6)
# 파이썬에 재귀제한이 걸려 있어 허용 범위를 넓혀준다.
input = sys.stdin.readline
# 백준은 이거 해야하는 듯..

def DFS(start):
    check[start] = 1
    for i in arr[start]:    # arr[start]에서
        if not check[i]:   # 이를 check에 넣었을 때 0일 경우
            DFS(i) # DFS로 들어간다.

n, m = map(int, input().split())
check = [0 for _ in range(n+1)]
arr = [[] for _ in range(n+1)]

for _ in range(m):
    a, b= map(int, input().split())
    arr[a].append(b)
    arr[b].append(a)
    # b에는 a를, a에는 b를

cnt = 0
for i in range(1, n+1):
    if not check[i]:
        DFS(i)
        cnt += 1
print(cnt)
        
