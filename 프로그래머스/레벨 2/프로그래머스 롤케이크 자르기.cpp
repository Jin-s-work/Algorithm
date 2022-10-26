from collections import Counter
def solution(topping):
    answer = 0
    
    # 이분탐색..?
    
    arr = Counter(topping)
    s = set()
    
    for k in topping:    # 여기에서 k는 분기점이라고 할 수 있다.
        arr[k] -= 1      # k로 넘어간 경우 arr에서 1씩 줄어준다. 넘어갔다는 의미
        s.add(k)         # 그리고 이 수를 s에 넣어준다.
        if arr[k] == 0:  # 만약 k가 없는 경우에는 arr에서 pop해준다.
            arr.pop(k)   # 0일 경우는 없기 때문에 개수를 세어주면 안됨 다 없애줘야
            
        if len(arr) == len(s):      # 앞의 arr와 중복을 제거해 개수가 같은 s의 개수가 같으면
            answer += 1             # 되는 것이므로 경우의 수를 증가
        
    
    
    
    return answer
