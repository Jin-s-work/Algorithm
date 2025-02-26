

n, s = map(int, input().split())

arr = list(map(int, input().split()))

ans = 0

def DFS(num, S):
    global ans

    if num >= n:
        return
    if S + arr[num] == s:
        ans += 1

    DFS(num + 1, S + arr[num])
    DFS(num + 1, S)
    # 여기에서 arr[num]을 선수택하고 넘어가는 경우와
    # 안선택하고 넘어가는 경우의 

DFS(0, 0)
print(ans)