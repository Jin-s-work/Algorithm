from collections import deque

def BFS(start, check, arr):
    queue = deque([start])
    check[start] = True
    result = 1
    # 처음에 queue에 start를 넣어주고 시작한다.
    # 그리고 start는 지났으므로 check가 true
    
    while queue:                    # 저장된 queue가 없어질때까지 하기
        now = queue.popleft()
        for i in arr[now]:          # arr[now]에 대하여
            if check[i] == False:   # i가 만약 False일 경우
                result += 1         # 송전탑의 개수를 늘려주고
                queue.append(i)     # queue에 i를 넣어준다.
                check[i] = True     # 그리고 개수 세었으므로 check가 True
                
    return result
# BFS에서는 한 쪽 전력망에 속한 송전탑의 개수를 세어본다.

def solution(n, wires):
    answer = n
    # 2개로 나누어서 개수를 최대한 비슷하게 맞추기
    arr = [[] for _ in range(n+1)]
    # 빈 공간 n+1개 arr[[]] 만들기
    
    for a, b in wires:
        arr[a].append(b)
        arr[b].append(a)
    
    for start, not_visit in wires:
        check = [False] * (n+1)
        check[not_visit] = True    # not_visit인 경우에는 True이다.
        result = BFS(start, check, arr)
        # 한쪽 송전탑에 대하여 개수를 세어주고 result에 넣어준다.
        
        if abs(result - (n - result)) < answer:
            answer = abs(result - (n - result))
        # 남은 송전탑들과의 차이를 확인하여 제일 큰 경우를 갱신해준다.
        
    return answer