def solution(s):
    answer = 0
    
    arr = list(s)
    ## deque가 아닌 list를 통해서도 stack으로 쓸 수가 있다..
    for _ in range(len(s)):
        
        st = []
        for i in range(len(arr)):
            if len(st) > 0:
                if st[-1] == '(' and arr[i] == ')':
                    st.pop()
                elif st[-1] == '{' and arr[i] == '}':
                    st.pop()
                elif st[-1] == '[' and arr[i] == ']':
                    st.pop()
                else:
                    st.append(arr[i])
            else:
                st.append(arr[i])
        if len(st) == 0:
            answer+=1
        arr.append(arr.pop(0))
                    
        
        
        
    
    return answer
