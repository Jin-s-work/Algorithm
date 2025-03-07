from collections import deque

def solution(skill, skill_trees):
    answer = 0
    
    for skill_tree in skill_trees:
        q = deque(skill)
        
        check = True
        for s in skill_tree:
            if s in q:
                # 어차피 없는 단어는 지나가므로 있는거만 하면 된다.
                if s != q.popleft():
                    check = False
                    break
        
        if check:
            answer += 1
    
    
    
    return answer