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

    for i in range(cnt, n+1):
        if not check[i]:
            arr[num] = i
            DFS(num+1, i)
            # 여기에서도 i+1이 아니라 i를 해주어야 
            # 비내림차순 즉 같거나 큰 순서로 되는 오름차순
        
        
DFS(0,1)
