# 너무 스트레스 받아서 그냥 이대로 낼래...

import sys
input = sys.stdin.readline

N, M = map(int, input().split())
MAX = int((2*N)**0.5)+1
small_rocks = [False]*N
for _ in range(M) :
  small_rocks[int(input()) - 1] = True

dp = [[N]*MAX for _ in range(N)]
if not small_rocks[1] :
  dp[1][0] = 1 
for i in range(1, N-1) :
  if small_rocks[i] :
    continue
  for j in range(MAX) :
    if dp[i][j] == N :
      continue
    for k in [j-1, j, j+1] :
      if -1 < k < MAX and i+k+1 < N and not small_rocks[i+k+1]:
        dp[i+k+1][k] = min(dp[i+k+1][k], dp[i][j] + 1)

answer = min(dp[-1])
print(answer if answer < N else -1)
