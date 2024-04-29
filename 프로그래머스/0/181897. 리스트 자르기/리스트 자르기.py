def solution(n, slicer, num_list):
    answer = []
    
    if n == 1:
        answer = num_list[:slicer[1]+1]
    elif n == 2:
        answer = num_list[slicer[0]:]
    elif n == 3:
        answer = num_list[slicer[0]:slicer[1]+1]
    elif n == 4:
        for i in range(slicer[0], slicer[1]+1, slicer[2]):
            answer.append(num_list[i])
        
        
    return answer