from collections import deque

def solution(queue1, queue2):
    answer = -1
    
    s1 = sum(queue1)
    s2 = sum(queue2)
    q1 = deque(queue1)
    q2 = deque(queue2)
    
    for i in range(len(queue1) * 4 + 1):
        if s1 < s2:
            x = q2.popleft()
            s1 += x
            s2 -= x
            q1.append(x)
        elif s1 > s2:
            x = q1.popleft()
            s1 -= x
            s2 += x
            q2.append(x)
        else:
            return i
    
    return answer


# from collections import deque
# def solution(queue1, queue2):
#     answer = -1
    
#     sum1 = sum(queue1)
#     sum2 = sum(queue2)
#     queue1 = deque(queue1)
#     queue2 = deque(queue2)
    
#     # 4개의 큐 길이 정도 번 하면 된다.
#     for i in range(len(queue1) * 4 + 1):
#         if sum1 > sum2:
#             x = queue1.popleft()
#             sum1 -= x
#             sum2 += x
#             queue2.append(x)
#         elif sum1 < sum2:
#             x = queue2.popleft()
#             sum2 -= x
#             sum1 += x
#             queue1.append(x)
#         else:
#             return i
            
    
#     return answer