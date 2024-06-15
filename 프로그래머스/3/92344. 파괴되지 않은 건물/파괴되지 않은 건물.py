def solution(board, skill):
    answer = 0
    
    n, m = len(board), len(board[0])
    arr = [[0] * (m + 1) for _ in range(n + 1)]
    for type, r1, c1, r2, c2, degree in skill:
        if type == 1:
            arr[r1][c1] -= degree
            arr[r2 + 1][c2 + 1] -= degree
            arr[r1][c2 + 1] += degree
            arr[r2 + 1][c1] += degree
        else:
            arr[r1][c1] += degree
            arr[r2 + 1][c2 + 1] += degree
            arr[r1][c2 + 1] -= degree
            arr[r2 + 1][c1] -= degree
    # 누적합을 구하기 위해 양 끝의 점들만 마킹을 해둔 뒤에 누적합을 이용해서 나중에 다 더해준다.
    
    for i in range(n):
        for j in range(1, m):
            arr[i][j] += arr[i][j-1]
    
    for j in range(m):
        for i in range(1, n):
            arr[i][j] += arr[i-1][j]
    
    for i in range(n):
        for j in range(m):
            board[i][j] += arr[i][j]
            if board[i][j] > 0:
                answer += 1
    
    
    return answer