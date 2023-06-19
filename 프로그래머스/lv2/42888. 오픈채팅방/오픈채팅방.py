def solution(record):
    answer = []
    
    arr = dict()
    num = 0
    
    for k in record:
        k = k.split(" ")
        if k[0] == "Enter":
            arr[k[1]] = k[2]
        elif k[0] == "Change":
            arr[k[1]] = k[2]
    # Enter나 Change의 경우 arr의 값을 바꾸어 준다.
            
    for k in record:
        k = k.split(" ")
        st = ""
        if k[0] == "Enter":
            st += arr[k[1]]
            st += "님이 들어왔습니다."
            answer.append(st)
        elif k[0] == "Leave":
            st += arr[k[1]]
            st += "님이 나갔습니다."
            answer.append(st)
    
    
    
    return answer