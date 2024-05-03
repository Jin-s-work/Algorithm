def solution(sequence, k):
    answer = []
    
    Min = 1000001
    s = 0
    left = 0
    right = 0
    while right < len(sequence):
        
        if s < k:
            s += sequence[right]
            right += 1
        elif s > k:
            s -= sequence[left]
            left += 1
        else:
            if (right - left) < Min:
                Min = right - left
                answer = [left, right - 1]
                
            s -= sequence[left]
            left += 1
    
    while s >= k and left < len(sequence):
        if s == k:
            if right - left < Min:
                Min = right - left
                answer = [left, right - 1]
        s -= sequence[left]
        left += 1

            
    
    return answer