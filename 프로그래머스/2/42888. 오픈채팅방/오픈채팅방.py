def solution(record):
    answer = []
    
    dic = dict()
    
    for k in record:
        k = k.split(" ")
        
        if k[0] == "Enter":
            dic[k[1]] = k[2]
            # answer.append(dic[k[1]] + "님이 들어왔습니다.")
        elif k[0] == "Change":
            dic[k[1]] = k[2]
            # answer.append(dic[k[1]] + "님이 나갔습니다.")
            # dic[k[1]] = 0

    for k in record:
        k = k.split(" ")
        if k[0] == "Enter":
            answer.append(dic[k[1]] + "님이 들어왔습니다.")
        elif k[0] == "Leave":
            answer.append(dic[k[1]] + "님이 나갔습니다.")
    
    
    return answer