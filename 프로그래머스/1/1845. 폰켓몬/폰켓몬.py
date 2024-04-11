def solution(nums):
    answer = 0
    
    n = len(nums) // 2
    
    s = set()
    for k in nums:
        s.add(k)
    
    answer = min(len(s), n)
    
    
    return answer