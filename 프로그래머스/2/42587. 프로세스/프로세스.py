
def solution(priorities, location):
    answer = 0
    
    arr = sorted(priorities, reverse = True)
    b = 0
    
    while True:
        for i, priority in enumerate(priorities):
            num = arr[b]
            
            if priority == num:
                b += 1
                answer += 1
                if location == i:
                    break
        else:           # 이 else는 for문을 모두 지났을때 발생한다.
            continue    # for 문을 모두 지나도 location이 i를 만나지 않는 경우 다시 while 실행
        break
            
    
    return answer