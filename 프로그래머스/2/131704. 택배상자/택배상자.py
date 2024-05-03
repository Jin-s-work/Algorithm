def solution(order):
    answer = 0
    
    st = []
    n = len(order)
    i = 1
    now = 0
    while i < n + 1:
        st.append(i)
        while st[-1] == order[now]:
            now += 1
            st.pop()
            if len(st) == 0:
                break
        i += 1
        
    return now