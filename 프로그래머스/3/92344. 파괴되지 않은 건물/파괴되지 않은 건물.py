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
    
    for i in range(1, n):
        for j in range(m):
            arr[i][j] += arr[i-1][j]
    
    # 이제까지 작성해온 끝점 배열인 arr을 행, 열에 대해 더해주면서 원래 더해주어야 할 값을 정한다.
    # 이렇게 사용하면 n*m을 쓰긴 하지만, skill * n * m 은 아니므로 시간 초과가 나지 않는다.

    for i in range(n):
        for j in range(m):
            board[i][j] += arr[i][j]
            if board[i][j] > 0:
                answer += 1
    
    
    return answer

# 누적합을 이해하는 것이 중요하다.
# 어떻게 ㅠ푸는 지는 이해가 되었지만 조금 더 익숙해질 필요가 있다.





