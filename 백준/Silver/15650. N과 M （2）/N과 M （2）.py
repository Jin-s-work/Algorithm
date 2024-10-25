

n, m = map(int, input().split())

arr = [0] * (n + 1)
def DFS(num, cnt):
    if num == m:
        for i in range(m):
            print(arr[i], end = " ")
        print()
        return

    for i in range(cnt, n+1):
        arr[num] = i
        DFS(num + 1, i + 1)
        # 어차피 같은 수가 아닌 증가하는 수열로 하기에 check를 해줄 필요가 없다.

DFS(0, 1)

