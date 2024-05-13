from collections import Counter

def solution(weights):
    answer = 0
    
    # 2:3, 1:2, 3:4
    
    counter = Counter(weights)
    for k, v in counter.items():
        if v >= 2:
            answer += v * (v-1) // 2
            
    weights = list(set(weights))
    for people in weights:
        for ratio in (3/4, 2/3, 1/2):
            if people * ratio in weights:
                answer += counter[people] * counter[people * ratio]
    
    
    
    return answer