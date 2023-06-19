def solution(numbers):
    answer = [-1] * len(numbers)
    
    st = []
    
    for i in range(len(numbers)):
        while st and numbers[st[-1]] < numbers[i]:
            answer[st.pop()] = numbers[i]
        st.append(i)
    
    
    return answer