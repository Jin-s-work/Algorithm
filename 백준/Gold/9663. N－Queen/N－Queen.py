

n = int(input())

arr = [-1] * n
# 퀸은 한 행에 하나만 가능

def is_valid(row, col):
    for i in range(row):
        if arr[i] == col or abs(arr[i] - col) == abs(i - row):
            return False
        # 같은 열에 다른 퀸이 있거나 or 대각선에 퀸이 있으면 False
    return True

ans = 0
def DFS(row):
    global ans
    if row == n:
        ans += 1
        return

    for col in range(n):
        # 현재 위치에 퀸을 놓을 수 있다면
        if is_valid(row, col):
            arr[row] = col
            # 퀸을 이 row에 배치한다. col로 배치
            DFS(row + 1)
            arr[row] = -1

DFS(0)
print(ans)

# 대각선을 확인하는 부분과 퀸을 한 열이나 행에 하나만 놓을 수 있다는 사실을 염두해서 푸는 것이 포인트