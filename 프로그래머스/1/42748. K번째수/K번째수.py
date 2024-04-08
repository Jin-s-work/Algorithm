def solution(array, commands):
    answer = []
    
    for i in range(len(commands)):
        arr = []
        for j in range(commands[i][0]-1, commands[i][1]):
            arr.append(array[j])
        arr.sort()
        answer.append(arr[commands[i][2]-1])
    
    
    
    return answer