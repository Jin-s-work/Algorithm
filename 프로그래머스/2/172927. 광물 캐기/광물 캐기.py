def solution(picks, minerals):
    answer = 0
    
    num = 0
    for k in picks:
        num += k
    
    gok = num * 5
    # 곡갱이로 최대 캘 수 있는 광물의 수
    
    if len(minerals) > num:
        minerals = minerals[:gok]
        
    next_mineral = [[0,0,0] for _ in range((len(minerals) // 5 + 1))]
    # 다음 광물을 위해서 배열을 만들어준다.
    
    for i in range(len(minerals)):
        if minerals[i] == 'diamond':
            next_mineral[i // 5][0] += 1
        elif minerals[i] == 'iron':
            next_mineral[i // 5][1] += 1
        elif minerals[i] == 'stone':
            next_mineral[i // 5][2] += 1
    
    next_mineral.sort(key=lambda x : (-x[0], -x[1], -x[2]))
    # 다이아몬드 철 돌 순으로 정렬
    
    for k in next_mineral:
        diamond, iron, stone = k
        # 이렇게 각각 넣어준다.
        
        for t in range(len(picks)):
            if picks[t] > 0 and t == 0:
                picks[t] -= 1
                answer += diamond + iron + stone
                # 각각의 개수만큼 더해주기 (다이아몬드 곡괭이를 사용)
                break
            elif picks[t] > 0 and t == 1:
                picks[t] -= 1
                answer += (5 * diamond + iron + stone)
                break
            elif picks[t] > 0 and t == 2:
                picks[t] -= 1
                answer += (25 * diamond + 5 * iron + stone)
                break
    
    
    return answer

    
    
   