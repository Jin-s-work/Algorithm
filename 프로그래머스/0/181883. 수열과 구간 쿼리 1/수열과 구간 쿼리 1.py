def solution(arr, queries):
    answer = []
    
    for k in queries:
        for i in range(k[0], k[1] + 1):
            arr[i] += 1
    
    return arr