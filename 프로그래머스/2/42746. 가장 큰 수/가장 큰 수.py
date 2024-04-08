def solution(numbers):
    answer = ''
    
    arr = list(map(str, numbers))
    arr.sort(key=lambda x : x * 3, reverse=True)
    
    answer = str(int("".join(arr)))
    
    return answer