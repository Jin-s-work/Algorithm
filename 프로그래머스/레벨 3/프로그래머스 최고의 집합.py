def solution(n, s):
    answer = []
    
    if n > s:
        return [-1]
    else:
        arr = []
        div = s // n
        rem = s % n
        # 몫만큼을 넣어주어야 한다.
        # 7을 3개의 자연수로 나누어줄 때
        # 2 2 2를 넣어주고 나머지인 1을 마지막에만 더해줌
        
        for i in range(n):
            arr.append(div)
        for i in range(0,rem):
            arr[n-i-1] += 1
    
    return arr
