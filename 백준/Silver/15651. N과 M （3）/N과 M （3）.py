

n, m = map(int, input().split())

arr = [0] * (n + 1)

def DFS(num):
    if num == m:
        for i in range(m):
            print(arr[i], end = " ")
        print()
        return

    for i in range(1, n + 1):
        arr[num] = i
        DFS(num + 1)

DFS(0)