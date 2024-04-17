def solution(msg):
    answer = []
    
    arr = {}
    for i in range(26):
        arr[chr(65 + i)] = i + 1
        # arr[단어] = i + 1
    
    a, b = 0, 0
    while True:
        b += 1   # b를 늘려나가면서 
        if b == len(msg):
            answer.append(arr[msg[a:b]]) # b가 끝에 도달하면 arr에 a에서 부터 b까지를 넣어준다.
            break
        if msg[a:b+1] not in arr:    # a에서 b까지 아직 arr안에 없을 경우
            arr[msg[a:b+1]] = len(arr) + 1  # arr에 len(arr) + 1 즉 제일 끝에 넣어주는 느낌
            answer.append(arr[msg[a:b]]) # 그리고 그 전까지의 a : b - 1 까지의 위치를 넣어준다.
            a = b        # 그리고 a를 b위치로 가서 새로 해준다.
    
    
    return answer

