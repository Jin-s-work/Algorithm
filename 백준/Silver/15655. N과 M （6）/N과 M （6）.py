import sys
# sys.setrecursionlimit(10**6)
input = sys.stdin.readline

n, m = map(int, input().split())
arr = list(map(int, input().split()))
arr.sort()

ans = []

def DFS(num):
    # 밑에가 바뀌었으므로 ans의 크기가 도달하면 출력
    if len(ans) == m:
        for i in range(m):
            print(ans[i], end = " ")
        print()
        return

    for i in range(num, n):
        if arr[i] not in ans:
            ans.append(arr[i])
            DFS(i+1)
            ans.pop()
            # DFS에서 i+1로 늘리면서 range(num, n)
            # 에서 num을 계속 증가시켜준다.
            # 원래 num을 1씩 늘렸지만 이제는 i를 1더해서 넣어서 해준다.
 
        
DFS(0)
