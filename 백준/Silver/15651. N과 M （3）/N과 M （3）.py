import sys
# sys.setrecursionlimit(10**6)
input = sys.stdin.readline

n, m = map(int, input().split())


check = [0] * (n+1)
arr = [0] * (n+1)

def DFS(num, cnt):
    if num == m:
        for i in range(m):
            print(arr[i], end = " ")
        print()
        return

    for i in range(1, n+1):
        if not check[i]:
            arr[num] = i
            DFS(num+1, i+1)
        
        
DFS(0,1)
