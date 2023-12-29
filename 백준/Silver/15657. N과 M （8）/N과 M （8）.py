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
        ans.append(arr[i])
        DFS(i)
        ans.pop()
    # 원래의 arr[i]가 ans에 있는지 확인하는 과정은 중복을 제거하기 위함이다.
    # 오름차순이 아니므로 n으로 바꾼다.            
        
DFS(0)


