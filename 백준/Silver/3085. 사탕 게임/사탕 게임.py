

n = int(input())

arr = []
for _ in range(n):
    tmp = list(input())
    arr.append(tmp)

# 한번만 바꾸고 거기에 대해서 검사
def count_max(arr):
    Max = 1
    for i in range(n):
        cnt = 1
        for j in range(1, n):
            if arr[i][j] == arr[i][j-1]:
                cnt += 1
                Max = max(Max, cnt)
            else:
                cnt = 1

        cnt = 1
        for j in range(1, n):
            if arr[j][i] == arr[j-1][i]:
                cnt += 1
                Max = max(Max, cnt)
            else:
                cnt = 1

    return Max

ans = 0
for i in range(n):
    for j in range(n):
        if i + 1 < n:
            arr[i][j], arr[i+1][j] = arr[i+1][j], arr[i][j]
            ans = max(ans, count_max(arr))
            arr[i][j], arr[i + 1][j] = arr[i + 1][j], arr[i][j]
        if j + 1 < n:
            arr[i][j + 1], arr[i][j] = arr[i][j], arr[i][j + 1]
            ans = max(ans, count_max(arr))
            arr[i][j + 1], arr[i][j] = arr[i][j], arr[i][j + 1]
# 문자열은 불변이라 이렇게 바꾸면 안되고 입력받을때 리스트로 받아야 한다.

print(ans)