def solution(money):
    answer = 0

    n = len(money)
    dp_one = [0] * 1000001
    dp_two = [0] * 1000001
    
    dp_one[0] = money[0]
    dp_one[1] = dp_one[0]
    dp_two[1] = money[1]
    
    for i in range(2, len(money)):
        dp_one[i] = max(dp_one[i-2] + money[i], dp_one[i-1])
        dp_two[i] = max(dp_two[i-2] + money[i], dp_two[i-1])
    
    answer = max(dp_one[n-2], dp_two[n-1])
    
    return answer