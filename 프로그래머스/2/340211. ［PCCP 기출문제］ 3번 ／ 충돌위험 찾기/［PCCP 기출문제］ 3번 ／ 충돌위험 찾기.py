# from collections import defaultdict

# def solution(points, routes):
#     answer = 0
    
#     # points는 시작 포인트들
#     # routes는 i+1번째 로봇이 j+1번째로 방문하는 포인트
    
#     timeline = defaultdict(lambda : defaultdict(int))
#     point_arr = {i + 1 : (points[i][0], points[i][1]) for i in range(len(points))}
    
#     for route in routes:
#         now = 0
#         for i in range(len(route) - 1):
#             start = point_arr[route[i]]
#             end = point_arr[route[i + 1]]
            
#             move = abs(start[0] - end[0]) + abs(start[1] - end[1])
#             r_move = 1 if start[0] < end[0] else -1
#             c_move = 1 if start[1] < end[1] else -1
            
#             r, c = start
#             while r != end[0]:
#                 timeline[(r, c)][now] += 1
#                 r += r_move
#                 now += 1
#             while c != end[1]:
#                 timeline[(r, c)][now] += 1
#                 c += c_move
#                 now += 1
            
#             timeline[(r, c)][now] += 1
#             # now += 1
    
        
        
#     risk = 0
#     for k in timeline:
#         for time in timeline[k]:
#             if timeline[k][time] > 1:
#                 risk += 1
                
                
#     return risk

from collections import defaultdict

def solution(points, routes):
    # 포인트 번호에 따른 좌표 정보 저장
    point_dict = {i + 1: (points[i][0], points[i][1]) for i in range(len(points))}

    # 시간별 좌표마다 로봇이 도착한 횟수를 저장하는 딕셔너리
    time_position_count = defaultdict(int)

    # 로봇들의 이동 경로 처리
    for route in routes:
        current_time = 0

        # 0초일 때 첫 포인트에 도착하는 것을 기록
        start_point = point_dict[route[0]]
        time_position_count[(current_time, start_point[0], start_point[1])] += 1

        for i in range(len(route) - 1):
            start = point_dict[route[i]]
            end = point_dict[route[i + 1]]

            # 현재 위치에서 목표 위치로 이동 (r 좌표를 먼저 이동, 그 다음 c 좌표 이동)
            r_start, c_start = start
            r_end, c_end = end

            # r 좌표 이동
            while r_start != r_end:
                if r_start < r_end:
                    r_start += 1
                else:
                    r_start -= 1
                current_time += 1
                time_position_count[(current_time, r_start, c_start)] += 1

            # c 좌표 이동
            while c_start != c_end:
                if c_start < c_end:
                    c_start += 1
                else:
                    c_start -= 1
                current_time += 1
                time_position_count[(current_time, r_start, c_start)] += 1

    # 충돌 횟수 계산
    danger_count = 0
    for value in time_position_count.values():
        if value > 1:
            danger_count += 1  # 충돌은 도착한 로봇 수 - 1 번 발생

    return danger_count
