import math
from itertools import permutations

def solution(numbers):
    answer = 0
    n = len(numbers)
    
    def sosu(num):
        if num == 0 or num == 1:
            return False
        elif num == 2:
            return True
        
        for i in range(2, int(math.sqrt(num) + 1)):
            if num % i == 0:
                return False
        return True

    numbers = list(numbers)
    s = set()
    
    for i in range(n):
        for k in list(permutations(numbers, i + 1)):
            st = int("".join(k))

            if st not in s:
                s.add(st)
                if sosu(st):
                    answer += 1
                
    
    return answer