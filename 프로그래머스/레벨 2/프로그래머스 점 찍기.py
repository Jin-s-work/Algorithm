def solution(k, d):
    answer = 0
    
    for i in range(0, d+1, k):
        y = int((d*d - i*i) ** (1/2))
        answer += (y // k+1)
        # 개수를 k+1로 나눈 몫이 개수이므로 answer에 그만큼 더해준다.
    
    return answer
