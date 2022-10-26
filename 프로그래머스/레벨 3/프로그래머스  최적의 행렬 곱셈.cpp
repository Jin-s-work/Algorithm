def solution(matrix_sizes):
    answer = 0
    # 백준에서도 풀었던 DP 문제이다.
    
    dp = [[0 for j in range(len(matrix_sizes))] for i in range(len(matrix_sizes))]
    
    for k in range(1, len(matrix_sizes)):
        for start in range(0, len(matrix_sizes) - k):
            end = k + start
            arr = []
            for i in range(start, end):
                arr.append(dp[start][i] + dp[i+1][end] + matrix_sizes[start][0] * matrix_sizes[i][1] * matrix_sizes[end][1])
                # (start - end까지 수) = (start - m 까지 수) + (m+1 - end까지의 수) + (두 행렬을 곱하기 위한 연산 수)
            dp[start][end] = min(arr)
    
    return dp[0][-1]   # start가 0이고 end는 제일 뒤에 있는 수가 최소이다.

# 5*3 3*10 10*6
#### 3 * 10 * 6
# 5*3 3*6
#### 5 * 3 * 6

#### 5 * 3 * 10
# 5*10 10*6
#### 5 * 10 * 6



