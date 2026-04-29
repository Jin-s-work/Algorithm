from collections import deque

def solution(m, n, h, w, drops):
    answer = []
    
    # 구역 후보가 여러개이면 그중 가장 위쪽 행, 그래도 여러 개면 가장 왼쪽에 위치한 구역을 선택
    
    # 시간이 지남에 따라서 drops가 떨어진다.
    # 이를 잘 피해서 사각형을 배치해야 한다.
    
    # 먼저 drops를 그래프에 입력해주고
    # 들어가지 않을 경우에는 INF
    
    INF = len(drops) + 1
    arr = [[INF] * (n + 1) for _ in range(m + 1)]
    
    for idx, (a, b) in enumerate(drops):
        arr[a][b] = idx
        
    def sliding(arr, k):
        q = deque()
        res = []
        
        for i, value in enumerate(arr):
            while q and arr[q[-1]] >= value:
                q.pop()
            
            q.append(i)
            
            if q[0] <= i - k:
                q.popleft()
            
            if i >= k-1:
                res.append(arr[q[0]])
        
        return res
    
    row_min = []
    for r in range(m):
        row_min.append(sliding(arr[r], w))
    
    wid_cnt = n - w + 1
    hgt_cnt = m - h + 1
    
    final = [[0] * wid_cnt for _ in range(hgt_cnt)]
    
    for c in range(wid_cnt):
        col = []
        for r in range(m):
            col.append(row_min[r][c])
        
        col_min = sliding(col, h)
        
        for r in range(hgt_cnt):
            final[r][c] = col_min[r]
    
    best = -1
    ans = [0, 0]
    
    for r in range(hgt_cnt):
        for c in range(wid_cnt):
            if final[r][c] > best:
                best = final[r][c]
                ans = [r, c]
    
    
    
    return ans