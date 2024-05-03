def solution(numbers, target):
    answer = 0
    
    def DFS(arr, num, idx, target):
        ans = 0
        if idx == len(numbers):
            if num == target:
                return 1
            else:
                return 0
        
        ans += DFS(arr, num + arr[idx], idx + 1, target)
        ans += DFS(arr, num - arr[idx], idx + 1, target)
        
        return ans
    
    answer = DFS(numbers, 0, 0, target)
    
    return answer