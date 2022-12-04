from collections import Counter

def solution(k, tangerine):
    answer = 0
    
    # 1 3 2 5 4 5 2 3
    
    arr = sorted(Counter(tangerine).items(), reverse=True, key = lambda x : x[1])
    # items로 수를 센 다음에 x[1] 즉 개수에 따라 정렬해준다.
    
    for key, value in arr:
        if k <= 0:
            break
            # 0이거나 음수일 경우 끝내줌
            
        k -= value
        # 그만큼의 개수가 있으면 빼준다.
        answer += 1
    
    # 딕셔너리를 사용하여 개수를 세준 다음, lambda를 통해서 x[1]로 하여금 맞는 개수를 정렬해주고
    # 개수를 빼가면서 종류를 늘려주는 것이 포인트
    
    return answer
