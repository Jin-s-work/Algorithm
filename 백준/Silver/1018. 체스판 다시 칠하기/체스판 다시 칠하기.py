


n, m = map(int, input().split())

arr = []
for i in range(n):
    st = input()
    arr.append(st)

white = ["WBWBWBWB", "BWBWBWBW", "WBWBWBWB", "BWBWBWBW", "WBWBWBWB", "BWBWBWBW", "WBWBWBWB", "BWBWBWBW"]
black = ["BWBWBWBW", "WBWBWBWB", "BWBWBWBW", "WBWBWBWB", "BWBWBWBW", "WBWBWBWB", "BWBWBWBW", "WBWBWBWB"]
# 8*8 행렬을 그냥 만들어서 다른 부분을 찾아주면 된다.

def cal(x, y, pattern):
    cnt = 0
    for i in range(8):
        for j in range(8):
            if arr[x+i][y+j] != pattern[i][j]:
                cnt += 1
    return cnt



ans = 100
cost_b, cost_w = 100, 100
# 미만이니까 -7로 해야한다.
for i in range(n-7):
    for j in range(m-7):
        cost_b = min(cal(i, j, black), cost_b)
        cost_w = min(cal(i, j, white), cost_w)
        ans = min(ans, cost_b, cost_w)

print(ans)