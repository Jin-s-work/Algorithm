def rotate(arr, d):
    n = len(arr)
    check = [[0] * n for _ in range(n)]
    
    if d % 4 == 1:   # 90도 회전
        for i in range(n):
            for j in range(n):
                check[j][n - i - 1] = arr[i][j]
                # 90도 회전이므로 j도 앞으로 오고 두번째는 n-i-1로
    elif d % 4 == 2:   # 180도 회전
        for i in range(n):
            for j in range(n):
                check[n-i-1][n-j-1] = arr[i][j]
    elif d % 4 == 3:   # 270도 회전
        for i in range(n):
            for j in range(n):
                check[n-j-1][i] = arr[i][j]
    else:
        for i in range(n):
            for j in range(n):
                check[i][j] = arr[i][j]
    return check

def find(arr_lock):
    n = len(arr_lock) // 3
    for i in range(n, n * 2):
        for j in range(n, n * 2):
            if arr_lock[i][j] != 1:
                return False     # 하나라도 1이 아니면 안되는 것
    return True      # 다 될 경우 True를 한다.

def solution(key, lock):
    answer = True
    
    # key와 lock을 더했을 때 lock의 모든 원소가 1일 경우 자물쇠를 열 수 있다.
    
    m = len(key)
    n = len(lock)
    
    # 열쇠를 (M,M)으로 자물쇠의 시작부분 (0,0)도 열기 위해 자물쇠의 원래 크기의
    # 3배를 하고 원본을 가운데에 두었다.
    arr_lock = [[0] * (n * 3) for _ in range(n * 3)]
    # 최대한 크게 하여 탐색하기 위하여 3배씩을 해서 큰 배열을 만들어준다.
    
    for i in range(n):
        for j in range(n):
            arr_lock[n+i][n+j] = lock[i][j]
    # arr_lock에 lock[i][j]을 n씩 평행이동 시킨 arr_lock을 만든다.
    ### 새로운 자물쇠의 중앙 부분에 기존의 자물쇠를 넣었다...!
    # 중앙 부분에 넣기 위해 x,y에 n씩을 더해서 넣어줌
    
    # 열쇠를 (1,1)부터 (n*2, n*2)까지 이동시키며 확인한다.
    for i in range(1, n*2):
        for j in range(1, n*2):
            # 회전시키며 확인해준다.
            for d in range(4):
                r = rotate(key, d)  # d로 하여금 모든 방향을 해본다.
                for x in range(m):
                    for y in range(m):
                        arr_lock[x + i][y + j] += r[x][y]
                # arr_lock에 회전한 r[x][y]를 더해본다.
                # lock + key가 1인지 확인하기 위하여
                # arr_lock은 [x+i][y+j]로 들어갔기에 비교를 이렇게 해야함
                
                if find(arr_lock):
                    return True
                # arr_lock을 넣어보았을 때 True가 나오면 된거다.
                
                for x in range(m):
                    for y in range(m):
                        arr_lock[x+i][y+j] -= r[x][y]
                # 아닐 경우 다시 돌려준다.
    
    # 리턴이 되지 않을 경우 안되는 것이다.
    return False
