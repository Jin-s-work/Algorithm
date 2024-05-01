def solution(n, stations, w):
    answer = 0

    range_num = 2 * w + 1
    last = 0

    for k in stations:
        start = max(1, k - w)
        end = min(n, k + w)
        
        if last + 1 < start:
            empty_range = start - last - 1
            answer += (empty_range + range_num - 1) // range_num
        
        last = max(last, end)
        
    if last < n:
        empty_range = n - last
        answer += (empty_range + range_num - 1) // range_num
        
    # 원래 했던 범위들을 찾아서 새로운 배열에 넣은 다음에 계산하면 배열의 크기가 커질 수 있으므로
    # 제일 마지막에 커버된 인덱스인 last를 설정해서 그 전까지의 범위를 각각 더해주고
    # 맨 마지막에도 하나 남으므로 끝난 뒤에도 한번 한다.
    
    return answer