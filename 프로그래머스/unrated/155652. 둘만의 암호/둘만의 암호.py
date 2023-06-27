def solution(s, skip, index):
    answer = ''
    
    alp = 'abcdefghijklmnopqrstuvwxyz'
    
        
    for k in list(skip):
        alp = alp.replace(k, '')
    
    for k in s:
        answer += alp[(alp.find(k) + index) % len(alp)]
    
    return answer