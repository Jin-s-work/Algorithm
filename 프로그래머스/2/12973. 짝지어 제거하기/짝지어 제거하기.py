from collections import deque

def solution(s):
    answer = 0

    q = deque()
    for i in range(len(s)):
        if len(q) == 0 or q[-1] != s[i]:
            q.append(s[i])
        elif q[-1] == s[i]:
            k = q.pop()
        
    if len(q) == 0:
        answer = 1
    else:
        answer = 0

    return answer