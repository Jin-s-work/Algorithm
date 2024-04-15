def solution(arr):
    answer = []
    
    tmp = -1
    for k in arr:
        if k == tmp:
            continue
        else:
            tmp = k
            answer.append(k)
    
    
    
    return answer