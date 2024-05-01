def solution(scores):
    answer = 0
    
    one = scores[0][0]
    two = scores[0][1]
    s = one + two
    
    # 처음을 내림차순, 다음을 오름차순으로 하면
    # 뒤에 있을 수록 무조건 앞의 학생의 점수보다 작고, 
    # 두번째 점수가 먼저 탐색하는 학생의 두번째 점수보다 작은 경우가 단 하나라도 있으면 해당 학생보다
    # 두 점수가 높은 학생이 있음을 보장한다.
    scores.sort(key=lambda x : (-x[0], x[1]))
    Max_b = 0
    
    for a, b in scores:
        if one < a and two < b:
            return -1
        
        if b >= Max_b:
            Max_b = b
            if a + b > s:
                answer += 1
    
    
    return answer + 1