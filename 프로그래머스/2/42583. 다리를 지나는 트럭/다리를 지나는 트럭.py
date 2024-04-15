from collections import deque
def solution(bridge_length, weight, truck_weights):
    answer = 0
    
    bridge = deque([0] * bridge_length)
    truck_weights = deque(truck_weights)
    
    now_weight = 0
    while len(truck_weights) != 0:
        answer += 1
        now_weight -= bridge.popleft()
        
        if now_weight + truck_weights[0] <= weight:
            # 브릿지에 트럭을 넣을 수 있는 경우
            now_weight += truck_weights[0]
            bridge.append(truck_weights.popleft())
        else:
            bridge.append(0)
            # 안되는 경우에도 0을 넣으면서 시간을 지나게 한다.
        
    answer += bridge_length
    # 마지막에 해결 못한거 후처리
        
    return answer



# def solution(bridge_length, weight, truck_weights):
#     answer = 0
    
#     bridge = [0 for _ in range(bridge_length)]
#     while bridge:
#         answer += 1
#         bridge.pop(0)
#         # 제일 끝을 pop하면서 answer를 늘려주기에 (시간을 늘려주기에)
        
#         if truck_weights:
#             if sum(bridge) + truck_weights[0] <= weight:
#                 num = truck_weights.pop(0)
#                 bridge.append(num)
#             else:
#                 bridge.append(0)
#                 # 안들어갈 경우에도 0을 넣음으로서 시간을 계산해준다.
    
#     return answer

#     # 1초 7    456
#     # 2초 0    456
#     # 3초 4    56
#     # 4초 45   6
#     # 5초 5    6
#     # 6초 0    6
#     # 7초 6    0
#     # 8초
    
