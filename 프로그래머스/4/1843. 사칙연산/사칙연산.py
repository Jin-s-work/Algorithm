def solution(arr):
    answer = 0
    
    num_arr = []
    op = []
    for k in arr:
        if k != '+' and k != '-':
            num_arr.append(int(k))
        else:
            op.append(k)
            
    n = len(num_arr)
    import sys
    Max = sys.maxsize
    dp_min = [[Max] * n for _ in range(n)]
    dp_max = [[-Max] * n for _ in range(n)]
    
    for length in range(n):
        for start in range(n - length):
            end = start + length
            if start == end:
                dp_min[start][end] = dp_max[start][end] = num_arr[start]
                continue
            for mid in range(start, end):
                if op[mid] == '+':
                    dp_min[start][end] = min(dp_min[start][mid] + dp_min[mid + 1][end], dp_min[start][end])
                    dp_max[start][end] = max(dp_max[start][mid] + dp_max[mid + 1][end], dp_max[start][end])
                    # 최소는 min + min
                    # 최대는 max + max
                if op[mid] == '-':
                    dp_min[start][end] = min(dp_min[start][mid] - dp_max[mid + 1][end], dp_min[start][end])
                    dp_max[start][end] = max(dp_max[start][mid] - dp_min[mid + 1][end], dp_max[start][end])
                    # 최소는 min - max
                    # 최대는 max - min
                
    
    return dp_max[0][-1]