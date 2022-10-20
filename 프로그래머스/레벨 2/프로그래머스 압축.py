def solution(msg):
    answer = []
    arr = {}
    for i in range(26):
        arr[chr(65 + i)] = i + 1
    # chr = 아스키 코드 같은 것 (유니코드 반환)
    # 딕테이션을 사용하여 arr[단어] = i+1을 넣어준다.
    
    a, b = 0, 0
    # 투 포인터 처럼 두가지로 시작과 끝을 나타내준다.
    while True:
        b += 1  # 어차피 a:b를 해주려면 b가 하나 더 커야하므로 증가시켜준다.
        if b == len(msg):
            answer.append(arr[msg[a:b]])   # b가 끝난 경우 이 단어를 answer에 넣어줌
            break
        if msg[a:b+1] not in arr:          # 없는 경우에
            arr[msg[a:b+1]] = len(arr) + 1 # 단어에 대하여 arr의 길이를 넣어준다.
            answer.append(arr[msg[a:b]])
            a = b                          # 그리고 a = b로 해주고, 한개부터 시작
                    
    
    return answer
