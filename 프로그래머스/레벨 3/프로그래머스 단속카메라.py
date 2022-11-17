def solution(routes):
    answer = 1
    
    routes.sort()
    start = routes[0][1]
    
    for i in range(1, len(routes)):
        if routes[i][1] < start:
            start = routes[i][1]
            # 도착하는 게 전의 start보다 앞일 경우
            # start를 다시 도착으로 바꾸어준다. (진출 지점에 있어도 만난 경우다.)
            # 즉 전의 start보다 더 안쪽에 있을 경우 start를 더 안쪽의 도착 지점으로 바꾸어 줌
        if routes[i][0] > start:
            answer += 1
            start = routes[i][1]
            # 출발하는 경우가 start보다 뒤에 있을 경우 카메라를 늘려주고
            # start도 도착하는 경우로 바꾸어 준다.
            # start보다 시작부분이 뒤에 있을 경우 카메라를 늘려주어야 한다.
            # 늘리고, start를 그 뒤에 있는 부분으로 해준다.
            
            # 나중에 더 뒤인 경우가 생기면 늘려주고 뒤로 start를 해주는 것
            # sort 자체가 시작부분에 있어서 정렬되어 있기 때문이다.
            
    
    return answer

# -20 -15
# start = -15
# -18, -13의 경우 아무것도 해당안되서 넘어감..
# -14, -5  routes[i][0] > start 이므로 answer늘려주고
# 앞에 부분으로 넘어가므로 그 전까지의 경우에는 카메라 한대만 놓고 다음으로 넘어가면 된다는 의미
# start = -5     -5,-3의 경우 겹쳐있으므로 한번 더 안해도 된다..
# 처음부터 answer를 1로 하여 최소를 하였으므로 한번 움직였으므로 한번만 더 해주면 된다는 뜻..
