def solution(elements):
    answer = 0
    
    s = set()
    arr = elements * 2
    for i in range(len(elements)):
        for j in range(len(elements)):
            k = sum(arr[j:j+i+1])
            s.add(k)
    
    answer = len(s)
    
    return answer