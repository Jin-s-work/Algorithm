from collections import deque

def solution(plans):
    answer = []
    
    # 새로운 과제 할 시간이 되었을 떄, 진행 중이던 과제가 있다면 진행 중이던 과제를 멈추고 새로운 과제 시작
    # 진행중이던 과제를 끝냈을 떄, 잠시 멈춘 과제가 있으면 멈춘 과제를 이어서 진행한다.
    # 멈춰둔 과제가 여러 개일 경우, 가장 최근에 멈춘 과제부터 시작한다.
    
    # [name, start, playtime]
    
    for i in range(len(plans)):
        hour, minute = map(int, plans[i][1].split(":"))
        times = hour * 60 + minute
        
        plans[i][1] = int(times)
        plans[i][2] = int(plans[i][2])
        
    plans.sort(key=lambda x : x[1])
    
    arr = deque()
    left_time= 0
    
    for i in range(len(plans)):
        name, start, playtime = plans[i]
        
        while arr:
            name_d, playtime_d = arr.pop()
            if left_time >= playtime_d:
                left_time -= playtime_d
                answer.append(name_d)
            else:
                arr.append((name_d, playtime_d - left_time))
                break
        
        arr.append((name, playtime))
        
        if i < len(plans) - 1:
            next_time = plans[i+1][1]
            left_time = next_time - start
        
    while arr:
        name, _ = arr.pop()
        answer.append(name)
        
    
    
    return answer