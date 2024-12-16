

# 입장권에 알맞은 좌석에 앉아야 한다.
# 자기의 바로 왼쪽 또는 바로 오른쪽 좌석으로 자리 옮길 수 있다.
# VIP 회원 - 자기 좌석에만 앉아야 한다.
# VIP 좌석 번호들이 주어졌을때 사람들이 좌석에 앉는 서로 다른 방법의 가짓수

n = int(input())
m = int(input())
arr = [0] * (n)
for _ in range(m):
    a = int(input())
    arr[a-1] += 1
# 고정석 (오름차순)

# 1개 - 1
# 2개 - 12, 21
# 3개 - 123, 213, 132
# 4개 - 1234, 2134, 1324, 1243, 2143
dp = [0] * (n + 1)
dp[0] = 1
dp[1] = 1
for i in range(2, n+1):
    dp[i] = dp[i-1] + dp[i-2]

if m == 0:
    print(dp[n])
    exit()

ans = 1
num = 0
for k in arr:
    if k == 0:
        num += 1
    else:
        ans *= dp[num]
        num = 0

ans *= dp[num]

print(ans)