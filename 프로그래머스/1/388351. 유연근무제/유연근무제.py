

# def solution(schedules, timelogs, startday):
#     answer = 0
    
#     # 출근 + 10분까지 출근해야 한다.
#     # 토, 일의 시간은 이벤트에 영향 x
#     # 희망 시각에 늦지 않고 출근한 직원에게 상품주는 이벤트
#     # 모든 시각은 시에 100을 곱하고 분을 더한 정수
#     n = len(schedules)
#     check = [0] * (len(schedules))
    
#     cnt = 0  
#     for i in range(7):  
#         if startday in [6, 7]:  
#             startday = (startday % 7) + 1
#             continue
        
#         for j in range(n):
#             schedule_time = convertTime(schedules[j])  
#             latest_time = revertTime(schedule_time + 10)  
#             actual_time = timelogs[j][cnt]  

#             if latest_time < actual_time:  # 허용된 시간보다 늦게 출근하면 실패
#                 check[j] = -1  
        
#         cnt += 1  
#         startday = (startday % 7) + 1 

#     return check.count(0) 

def solution(schedules, timelogs, startday):
    n = len(schedules)
    eligible_employees = 0
    
    # 각 직원별로 확인
    for i in range(n):
        is_eligible = True
        
        # 일주일 동안의 출근 기록 확인
        for j in range(7):
            # 현재 요일 계산 (1: 월요일, ..., 7: 일요일)
            current_day = (startday + j - 1) % 7 + 1
            
            # 토요일(6)이나 일요일(7)이면 건너뛰기
            if current_day == 6 or current_day == 7:
                continue
            
            # 출근 희망 시각에 10분 추가
            deadline_minutes = (schedules[i] % 100) + 10
            deadline_hours = schedules[i] // 100
            
            # 분이 60을 넘으면 시간 조정
            if deadline_minutes >= 60:
                deadline_minutes -= 60
                deadline_hours += 1
            
            # 출근 인정 시각 계산
            deadline_time = deadline_hours * 100 + deadline_minutes
            
            # 출근 시각이 인정 시각보다 늦으면 상품 수령 자격 없음
            if timelogs[i][j] > deadline_time:
                is_eligible = False
                break
        
        # 모든 평일에 늦지 않았으면 상품 수령 자격 있음
        if is_eligible:
            eligible_employees += 1
    
    return eligible_employees
