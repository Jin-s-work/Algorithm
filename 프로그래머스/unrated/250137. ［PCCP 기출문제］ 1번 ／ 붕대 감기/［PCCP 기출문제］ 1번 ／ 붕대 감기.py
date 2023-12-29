def solution(bandage, health, attacks):
    answer = 0
    
    Max = health
    tmp = 0
    for i in range(len(attacks)-1):
        health -= attacks[i][1]
        tmp = attacks[i][0]
        
        if health <= 0:
            return -1
        
        # 사전 시간, 초당 회복량, 추가 회복량
        t = attacks[i+1][0] - attacks[i][0]
        health += ((t-1) // bandage[0]) * bandage[2] + (t-1) * bandage[1]
        if health >= Max:
            health = Max
    
    health -= attacks[len(attacks)-1][1]
    if health <= 0:
        return -1
        
        
        
    
    return health


# t초 동안 붕대 감으면서 1초마다 x만큼 회복
# t초 연속으로 붕대 성공하면 y만큼 체력 추가 회복

# 공격당하면 기술시 취소되거나 끝난다.
# 즉시 다시 사용하면 연속 성공 시간이 0으로 초기화

