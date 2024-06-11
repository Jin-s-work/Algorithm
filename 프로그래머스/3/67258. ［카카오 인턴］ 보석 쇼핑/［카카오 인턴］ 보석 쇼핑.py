def solution(gems):
    answer = [0, len(gems)]
    
    jewel = len(set(gems))
    left, right = 0, 0
    dic = {gems[0] : 1}
    
    while left <= len(gems) and right <= len(gems):
        if len(dic) == jewel:
            if right - left < answer[1] - answer[0]:
                answer = [left, right]
            else:
                dic[gems[left]] -= 1
                if dic[gems[left]] == 0:
                    del dic[gems[left]]
                left += 1
            
        else:
            right += 1
            
            if right == len(gems):
                break
                
            if gems[right] in dic:
                dic[gems[right]] += 1
            else:
                dic[gems[right]] = 1
                
    
    
    return [answer[0] + 1, answer[1] + 1]