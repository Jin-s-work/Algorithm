def solution(clothes):
    answer = 1
    
    arr = {}
    
    for k in clothes:
        if k[1] in arr:
            arr[k[1]] += 1
        else:
            arr[k[1]] = 1
        # 처음에 숫자를 넣는 작업을 먼저 해야 한다.
    
    for k in arr.values():
        answer *= (k + 1)
    
    
    return answer - 1