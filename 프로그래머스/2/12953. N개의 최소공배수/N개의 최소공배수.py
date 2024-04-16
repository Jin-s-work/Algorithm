def solution(arr):
    answer = arr[0]
    
    def gcd(a, b):
        while b > 0:
            a, b = b, a % b
        return a
    
    def lcm(a, b):
        return (a * b) // gcd(a, b)
    
    for i in range(1, len(arr)):
        answer = lcm(answer, arr[i])
    
    return answer