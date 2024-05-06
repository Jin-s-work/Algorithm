def solution(skill, skill_trees):
    answer = 0
    
    for k in skill_trees:
        arr = list(skill)
        
        for s in k:
            if s in skill:
                if s != arr.pop(0):
                    break
        else:
            answer += 1
        # k에서 s들을 찾으면서 위에서 break가 일어나지 않을 경우 되는 거기에 answer += 1
    
    return answer