def solution(dirs):
    answer = 0
    
    arr = {'U' : (0, 1), 'D' : (0, -1), 'R' : (1, 0), 'L' : (-1, 0)}
    

    s = set()
    
    x, y = 0, 0
    for k in dirs:
        nx = x + arr[k][0]
        ny = y + arr[k][1]
        
        if -5<=nx<=5 and -5<=ny<=5:
            s.add((x, y, nx, ny))
            s.add((nx, ny, x, y))
            
            x = nx
            y = ny
    
    return len(s) // 2
        
    
    
