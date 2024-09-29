
def DFS(arr, idx, num, t):
    
    cnt = 0
    if idx == len(arr):
        if num == t:
            return 1
        else:
            return 0
    
    cnt += DFS(arr, idx + 1, num + arr[idx], t)
    cnt += DFS(arr, idx + 1, num - arr[idx], t)
    
    return cnt
    
    

def solution(numbers, target):
    answer = 0
    
    answer += DFS(numbers, 0, 0, target)
    
    return answer