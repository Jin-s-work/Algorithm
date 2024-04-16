def solution(n):
    answer = 0
    
    def find_one(num):
        cnt = 0
        while num > 0:
            if num % 2 == 1:
                cnt += 1
            num //= 2
        
        return cnt

    num = n + 1
    while True:
        if find_one(num) == find_one(n):
            answer = num
            break
        num += 1
    
    
    return answer