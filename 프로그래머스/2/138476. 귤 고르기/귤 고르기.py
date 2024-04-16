def solution(k, tangerine):
    answer = 0
    
    from collections import defaultdict

    # dictionary가 안되서 defaultdict를 사용하였다
    dic = defaultdict(int)
    for s in tangerine:
        dic[s] += 1
        
    arr = sorted(dic.items(), key=lambda x : x[1], reverse = True)
    
    cnt = 0
    for key, value in arr:
        cnt += value
        answer += 1
        if cnt >= k:
            return answer
    
    
    
    return answer