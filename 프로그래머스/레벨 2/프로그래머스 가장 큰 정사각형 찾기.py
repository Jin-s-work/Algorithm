def solution(board):
    answer = 1234
    
    n = len(board)
    m = len(board[0])
    # dp = [[1] * (m+1) for _ in range(n+1)]
    
    Max = board[0][0]
    for i in range(1,n):
        for j in range(1,m):
            if board[i][j] == 1:
                board[i][j] = 1 + min(board[i][j-1], board[i-1][j], board[i-1][j-1])
                Max = max(Max, board[i][j])

    return Max * Max
