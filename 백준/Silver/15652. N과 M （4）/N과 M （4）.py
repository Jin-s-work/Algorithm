

n, m = map(int, input().split())

arr = [0] * (n + 1)

def DFS(num, cnt):
    if num == m:
        for i in range(m):
            print(arr[i], end = " ")
        print()
        return

    for i in range(cnt, n + 1):
        arr[num] = i
        DFS(num + 1, i)
    
    # 현재의 숫자인 i를 넣어서 다음 순서에도 i도 넣어주는 경우를 포함시켜준다,
    # 포함 시켜주면 되는 것!

DFS(0, 1)