from itertools import combinations
from math import factorial

def solution(n, k):
    answer = []
    
    arr = list(range(1, n+1))
    
    while n != 0:
        num = factorial(n - 1)
        idx = (k - 1) // num
        # 현재 위치에서 몇번째를 선택해야 하는지 결정
        answer.append(arr.pop(idx))
        # 그 위치에 있는 값을 pop해서 answer에 넣는다.
        k %= num
        n -= 1
        # k를 업데이트 해서 다음 순서를 결정하고 한개 줄었으므로 n -= 1
    
    
    
    return answer