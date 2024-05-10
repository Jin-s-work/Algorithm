def solution(n):
    answer = []
    
    num = 1
    arr = [[0 for j in range(1, i + 1)] for i in range(1, n + 1)]
    
    a, b = -1, 0
    for i in range(n):
        for j in range(i, n):
            if i % 3 == 0:
                a += 1
            elif i % 3 == 1:
                b += 1
            else:
                a -= 1
                b -= 1
            
            arr[a][b] = num
            num += 1
            
    
    
    
    return sum(arr, [])