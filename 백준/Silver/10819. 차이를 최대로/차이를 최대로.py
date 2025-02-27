

n = int(input())

arr = list(map(int, input().split()))
check = [0] * (n + 1)
dp = [0] * (n + 1)

ans = 0
def DFS(num):
    global ans
    if num == n:
        s = 0
        for i in range(n-1):
            s += abs(dp[i] - dp[i + 1])

        ans = max(ans, s)
        return

    for i in range(n):
        if check[i]:
            continue

        # check로 방문 여부를 탐색해준다.
        # 그리고 num의 인덱스에 arr[i]를 넣어준다.
        check[i] = True
        dp[num] = arr[i]
        DFS(num + 1)
        check[i] = False


DFS(0)
print(ans)

# n이 작으니까 그냥 permutation으로 해도 8! 밖에 나오지 않는다.
# 사실 그리고 DFS라서 똑같은 8! 이다....