def solution(my_string):
    answer = []
    
    for i in range(52):
        answer.append(0)
    
    for k in my_string:
        if 'A' <= k <= 'Z':
            answer[ord(k) - ord('A')] += 1
        elif 'a' <= k <= 'z':
            answer[ord(k) - ord('a') + 26] += 1
    
    
    return answer