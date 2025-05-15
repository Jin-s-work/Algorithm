

r, c =map(int, input().split())

arr = []
for i in range(r):
    st = input()
    arr.append(st)

ans = 0
dx = [0,0,1,-1]
dy = [1,-1,0,0]
check = [0] * 26

def DFS(x, y, num):
    global ans
    ans = max(ans, num)

    for i in range(4):
        nx = x + dx[i]
        ny = y + dy[i]

        if 0<=nx<r and 0<=ny<c:
            idx = ord(arr[nx][ny]) - ord('A')
            if not check[idx]:
                check[idx] = True
                DFS(nx, ny, num + 1)
                check[idx] = False

        # set으로 하면 시간복잡도가 너무 오래걸려서
        # 알파벳을 index를 통해서 True False로 방문 여부를 체크해준다.

check[ord(arr[0][0]) - ord('A')] = True
DFS(0, 0, 1)
print(ans)