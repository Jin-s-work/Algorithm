from collections import deque

def solution(prices):
    answer = []
    
    q = deque(prices)
    while q:
        num = q.popleft()

        cnt = 0
        # 지우면서 앞에는 빼주면 시간 복잡도가 줄어들고 코드가 간편해질 것
        for k in q:
            if k < num:
                cnt += 1
                break
            cnt += 1            
        answer.append(cnt)
            
    
    
    return answer