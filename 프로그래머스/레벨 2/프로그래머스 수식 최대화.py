from itertools import permutations
from collections import deque

def cal(priority, expression):
    arr = deque()
    st = ''
    
    for k in expression:
        if k.isdigit():
            st += k
            # k가 숫자일 경우 숫자를 문자 그대로 st에 더해준다.
        else:
            arr.append(st)
            st = ''
            arr.append(k)
            # k가 기호일 경우 들어온 st를 arr에 넣고 초기화한후
            # 기호도 arr에 넣어준다.
    arr.append(st)
    # 마지막의 st가 안들어오므로 arr에 넣어줌
    
    for op in priority:   # 기호의 순서대로인데 처음의 op를 먼저
        stack = []
        while len(arr) != 0:   # arr이 없어질때까지
            tmp = arr.popleft()
            if tmp == op:   # 만약 tmp와 op가 같을 경우에 계산을 해준다.
                result = str(eval(stack.pop() + op + arr.popleft()))
                stack.append(result)
                # stack의 직전 값과 op, arr를 한번 더 팝하여 다음 값을 구한다.
                # result 도 stack에 넣어줌
            else:
                stack.append(tmp)
                # op가 아닐 경우 stack에 다 넣어준다.
        arr = deque(stack)
        # 없어 진 경우 stack을 arr에 다시 넣고 다음 기호에 대해 진행해줌
        
    return int(arr.pop())
    # 다 끝나고 마지막 남은 arr를 pop해주면서 값을 리턴한다.
    
    

def solution(expression):
    answer = 0
    
    # + - * 의 순위를 마음대로
    for priority in list(permutations(['+', '-', '*'], 3)):
        answer = max(answer, abs(cal(priority, expression)))
    # 순서가 바뀔때마다 진행해줌
    
    return answer
