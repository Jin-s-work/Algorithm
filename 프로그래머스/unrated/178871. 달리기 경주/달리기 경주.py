def solution(players, callings):
    answer = []
    
    dict1 = {}
    dict2 = {}
    
    for idx, name in enumerate(players):
        dict1[idx+1] = name
        dict2[name] = idx+1
    
    for k in callings:
        num = dict2[k]
        prev = dict1[num-1]
        
        dict1[num-1], dict1[num] = dict1[num], dict1[num-1]
        dict2[prev], dict2[k] = dict2[k], dict2[prev]
    
    
    
    return list(dict1.values())