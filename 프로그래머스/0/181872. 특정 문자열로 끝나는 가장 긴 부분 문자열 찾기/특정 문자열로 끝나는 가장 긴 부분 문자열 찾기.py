def solution(myString, pat):
    # answer = ''
    
    for i in range(len(myString) - len(pat) + 1, 0, -1):
        if myString[i-1:i-1+len(pat)] == pat:
            return myString[:i-1+len(pat)]
        
    return ''