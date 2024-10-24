



arr = list(map(int, input().split()))
n = arr[0]
east = arr[1]
west = arr[2]
south = arr[3]
north = arr[4]

check = [[0] * 29 for _ in range(29)]
# 음수가 가능하므로 이렇게 하고 (14, 14)에서 시작해준다.

def DFS(num, p, x, y):
    if num == n:
        return p

    # 처음에 이런 풀이를 생각했는데 왜 안해봤을까
    ans = 0
    if check[x + 1][y] == 0:
        check[x+1][y] = 1
        ans += DFS(num + 1, p * east / 100, x + 1, y)
        check[x+1][y] = 0
    # 가고자 하는 방향이 아직 false일 경우 DFS로 가준다.
    if check[x - 1][y] == 0:
        check[x-1][y] = 1
        ans += DFS(num + 1, p * west / 100, x - 1, y)
        check[x-1][y] = 0

    if check[x][y-1] == 0:
        check[x][y-1] = 1
        ans += DFS(num + 1, p * south / 100, x, y - 1)
        check[x][y-1] = 0

    if check[x][y+1] == 0:
        check[x][y+1] = 1
        ans += DFS(num + 1, p * north / 100, x, y + 1)
        check[x][y+1] = 0

    return ans

check[14][14] = 1
print(DFS(0, 1, 14, 14))

