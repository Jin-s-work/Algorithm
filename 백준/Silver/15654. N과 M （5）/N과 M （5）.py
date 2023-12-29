import sys
# sys.setrecursionlimit(10**6)
input = sys.stdin.readline

n, m = map(int, input().split())
arr = list(map(int, input().split()))
arr.sort()

check = [0] * (n+1)
ans = []

def DFS(num):
    if num == m:
        for i in range(m):
            print(ans[i], end = " ")
        print()
        return

    for i in range(n):
        if arr[i] not in ans:
            ans.append(arr[i])
            DFS(num+1)
            ans.pop()
            
 
        
DFS(0)
