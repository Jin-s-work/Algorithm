from collections import deque

def solution(s):
    answer = True
    
    q = deque()
    for k in s:
        if k == ')' and len(q) == 0:
            return False
        elif k == ')' and len(q) != 0:
            q.pop()
        elif k == '(':
            q.append('(')
    

    if len(q) != 0:
        return False
    else:
        return True