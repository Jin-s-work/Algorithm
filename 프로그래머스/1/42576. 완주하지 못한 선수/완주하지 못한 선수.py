def solution(participant, completion):
    answer = ''
    
    participant.sort()
    completion.sort()
    
    if len(participant) == 1:
        answer = participant[0]
    
    for i in range(len(participant)-1):
        if participant[i] != completion[i]:
            answer = participant[i]
            break
        else:
            answer = participant[i+1]
    
    
    return answer