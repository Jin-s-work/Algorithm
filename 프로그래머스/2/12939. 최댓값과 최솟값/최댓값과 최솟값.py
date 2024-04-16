def solution(s):
    answer = ''
    
    arr = list(map(int, s.split(' ')))
    
    answer += str(min(arr))
    answer += " "
    answer += str(max(arr))
    
    return answer