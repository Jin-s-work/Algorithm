arr = [0] * 11
check = [0] * 11
def DFS(num):
    if num == m:
        for i in range(0, m):
            print(arr[i], end=' ')
        print()
        return
    for i in range(1, n+1):
        if check[i]:
            continue
        check[i] = True
        arr[num] = i
        DFS(num+1)
        check[i] = False

n, m = map(int, input().split())
DFS(0)
