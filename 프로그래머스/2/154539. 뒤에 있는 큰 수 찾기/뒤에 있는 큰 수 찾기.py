def solution(numbers):
    answer = [-1] * len(numbers)
    
    st = []
    for i in range(len(numbers)):
        # st가 남아있고, number의 제일 마지막 인덱스가 현재의 number보다 작을 경우에
        # st를 없애면서 제일 마지막 인덱스인 값에 numbers를 넣어준다.
        while st and numbers[st[-1]] < numbers[i]:
            answer[st.pop()] = numbers[i]
        # 위에서 다음 값과 같거나 더 클 경우에는 while문 진행안하고 st을 쌓아줌
        # 쌓다가 더 큰 수가 나오면 그때 그때 스택을 사용해서 불러오면서 비교해준다.
        
        # st에는 index들을 넣어준다.
        st.append(i)
    
    
    return answer