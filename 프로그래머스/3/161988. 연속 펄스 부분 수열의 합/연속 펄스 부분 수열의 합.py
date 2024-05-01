import sys

def solution(sequence):
    answer = -sys.maxsize
    
    # Num 을 마지막으로 하는 누적합의 최대를 구하려면
    # Num까지의 누적합 - Num이전까지 누적합의 최소값
    Mins1, Mins2 = 0, 0
    s1, s2 = 0, 0
    pulse = 1
    for i in range(len(sequence)):
        s1 += sequence[i] * pulse
        s2 -= sequence[i] * pulse
        
        answer = max(answer, s1 - Mins1, s2 - Mins2)
        
        Mins1 = min(Mins1, s1)
        Mins2 = min(Mins2, s2)
        pulse *= -1
        
            
    
    return answer