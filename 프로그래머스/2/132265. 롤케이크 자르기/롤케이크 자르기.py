from collections import Counter
def solution(topping):
    answer = 0
    
    arr = Counter(topping)
    s = set()
    for k in topping:
        # 전체인 arr을 일단 지정해놓고, topping을 순회하며 arr을 빼주고, s에 넣어준다.
        # arr[k]가 0이 될 경우 arr을 빼준다. 
        # 이렇게 전해주면서, arr와 s의 개수가 같아지면 answer를 증가시킴
        # s가 왼쪽, arr가 오른쪽 이다.
        arr[k] -= 1
        s.add(k)
        if arr[k] == 0:
            arr.pop(k)
        if len(arr) == len(s):
            answer += 1
    
    
    return answer