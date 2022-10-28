def solution(distance, scope, times):
    answer = 0
    
    # 근무 / 휴식
    # 위치 범위
    
    t = 0
    num = 0
    arr = [] # scope + time
    for i in range(len(scope)):
        if scope[i][0]  < scope[i][1]:   # scope는 정리 되어있지 않을 수 있다.
            arr.append([scope[i][0], scope[i][1], times[i][0], times[i][1]])
        else:
            arr.append([scope[i][1], scope[i][0], times[i][0], times[i][1]])
    arr.sort()
    
    while t < distance:
        t += 1    # 시간은 흘러감
        if arr[num][0] <= t and arr[num][1] >= t:   # 시간이 scope안에 있을때 진입
            now = (t - 1) % (arr[num][2] + arr[num][3])  # 1 빼준 시간에 대해
            # 경비의 근무와 휴식의 주기를 더해서 구한뒤에 나누어 나머지를 찾는다.
            # ** 여기서 now가 time[i][0]보다 작을 경우 근무 중인 것이다 -> 이건 생각함
            if now < arr[num][2]:   # 근무 중 발각
                break       # now가 만약 time[i][0]보다 작을 경우 멈춘다. 즉 아직 근무일 경우
        if arr[num][1] == t:   # 경비 없을 때
            num += 1           # 인덱스가 증가한다.
            if num == len(scope):     # 인덱스가 끝까지 가면 distance를 리턴한다.
                return distance
    
    return t
