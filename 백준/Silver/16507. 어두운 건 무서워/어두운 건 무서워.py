

n, m, q = map(int, input().split())

arr = [[0] * (n + 1)]
for _ in range(n):
    arr.append([0] + list(map(int, input().split())))

s = [[0] * (m + 1) for _ in range(n + 1)]

for i in range(1, n + 1):
    for j in range(1, m + 1):
        s[i][j] = arr[i][j] + (s[i-1][j] + s[i][j-1] - s[i-1][j-1])
# 이렇게 해야 0,1 1,0 에 대해서 더해주고, 중복인 0,0 부분만 빼주면 딱 그 값이 된다.
# 거기에 arr[i][j] 만 넣어주면

for _ in range(q):
    x1, y1, x2, y2 = map(int, input().split())
    total = s[x2][y2] - s[x2][y1 - 1] - s[x1 - 1][y2] + s[x1 - 1][y1 - 1]
    num = (x2 - x1 + 1) * (y2 - y1 + 1)
    print(total // num)
# 잘 생각해서 중복을 빼야 한다.
# 마지막에도 그 전의 칸인 x1-1, y1-1 이어야 한다.