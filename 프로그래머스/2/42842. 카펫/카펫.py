def solution(brown, yellow):
    answer = []
    
    brown -= 4
    brown //= 2
    a, b = 0, 0
    for i in range(10000):
        for j in range(10000):
            if i + j == brown and i * j == yellow:
                a = i
                b = j
                break
    
    if a >= b:
        answer.append(a+2)
        answer.append(b+2)
    else:
        answer.append(b+2)
        answer.append(a+2)
    
    return answer