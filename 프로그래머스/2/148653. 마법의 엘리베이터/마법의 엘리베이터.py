def solution(storey):
    answer = 0
    
    # dp로 0부터 시작해서 각각마다 얼마나 걸리는지를 넣어놓으면 될 듯
    # 아니다 dp로 하면 리스트가 너무 커서 오류날 듯
    # 그냥 그 수 자체로 계속 계산해야 한다.
    
    # 나머지가 5 이상일 경우에는 10층으로 올라가서 내려오는게 나음
    # 나머지가 5 이하일 경우에는 그냥 올라가는게 나음
    # 나머지가 5일 경우에는 그 윗자리가 5 이상일 경우에만 올라가야 최단개수가 된다.
    
    while storey:
        rem = storey % 10
        
        if rem > 5:
            answer += (10 - rem)
            storey += 10
        elif rem < 5:
            answer += rem
        else:
            if ((storey // 10) % 10) >= 5:
                storey += 10
            answer += rem
        
        storey //= 10
                

    return answer