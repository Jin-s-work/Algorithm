def solution(name):
    answer = 0
    
    # 기본 최소 좌우이동 횟수는 길이 - 1
    move_min = len(name) - 1
    for i, char in enumerate(name):
        # 위치의 알파벳 변경 최솟값 더하기
        answer += min(ord(char) - ord('A'), ord('Z') - ord(char) + 1)
        
        # 해당 알파벳 당므부터 연속된 A 문자열 찾기
        next = i + 1
        while next < len(name) and name[next] == 'A':
            next += 1
        # 아직 next가 name의 길이보다 작고, A일 경우 계속 넘어간다.
        
        # 기존값, 연속된 A의 왼쪽 시작 방식, 연속된 A의 오른쪽 시작 방식 비교하고 갱신
        move_min = min([move_min, 2 * i + len(name) - next, i + 2 * (len(name) - next)])
    
    answer += move_min
    
    
    return answer

            