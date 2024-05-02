def solution(target):
    answer = []
    
    scores = []
    scores.extend([(i, 'single') for i in range(1, 21)])
    scores.extend([(i * 2, 'double') for i in range(1, 21)])
    scores.extend([(i * 3, 'triple') for i in range(1, 21)])
    scores.append((50, 'bull'))
    # 한개를 넣어주고, 튜플 형태로 넣어주어야 하므로 append
    
    import sys
    dp = [(sys.maxsize , 0)] * (target + 1)
    # 투척 횟수, 싱글 / 불 갯수
    dp[0] = (0, 0)
    
    for score, kind in scores:
        for i in range(score, target + 1):
            # 현재 점수를 추가했을 때
            throw, single_bull = dp[i - score]
            throw += 1
            if kind == 'single' or kind == 'bull':
                single_bull += 1
            
            # 현재의 점수로 업데이트를 하거나 투척한 횟수가 같다면, 최대 싱글 / 불 횟수를 업데이트
            if throw < dp[i][0] or (throw == dp[i][0] and single_bull > dp[i][1]):
                dp[i] = (throw, single_bull)
    
    
    return list(dp[target])