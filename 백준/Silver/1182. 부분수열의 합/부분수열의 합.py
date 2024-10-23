

n, s = map(int, input().split())
arr = list(map(int, input().split()))
ans = 0

def DFS(num, Sum):
    global ans
    if num == n:
        return
    if Sum + arr[num] == s:
        ans += 1
    
    # 안더하고 가지 뻗어나가는 경우
    DFS(num + 1, Sum)
    # 더하고 가지 뻗어나가는 경
    DFS(num + 1, Sum + arr[num])
    return

DFS(0, 0)
print(ans)

