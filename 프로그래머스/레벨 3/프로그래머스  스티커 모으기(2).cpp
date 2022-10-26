def solution(sticker):
    answer = 0

    if len(sticker) == 1:
        return sticker[0]
    
    dp = [0 for _ in range(len(sticker))]  # 처음 스티커를 땠을때
    dp2 = [0 for _ in range(len(sticker))] # 처음 스티커를 때지 않았을 때
    
    dp[0] = sticker[0]
    dp[1] = sticker[0] # 처음에 땠으므로 1일때는 못하니까 똑같다.
    
    dp2[0] = 0   # 안땠으므로 0이다.
    dp2[1] = sticker[1]
    
    # 처음 사용유무에 따라서 넘겨준다.
    for i in range(2,len(sticker)-1):
        dp[i] = max(dp[i-2] + sticker[i], dp[i-1])
    for i in range(2, len(sticker)):
        dp2[i] = max(dp2[i-2] + sticker[i], dp2[i-1])
        
    num1 = max(dp)
    num2 = max(dp2)
    answer = max(num1, num2)
    
    # 파이썬도 사실 C++이랑 큰 차이는 없는 거 같다. 디피도 그렇고 DFS, BFS도 그렇고..

    return answer















