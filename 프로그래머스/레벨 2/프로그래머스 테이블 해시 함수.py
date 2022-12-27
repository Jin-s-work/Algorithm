def solution(data, col, row_begin, row_end):
    answer = 0
    
    # col 번째 컬럼의 값을 기준으로 오름차순 정렬을 하고, 값이 동일하면 첫 번째 컬럼의 값을
    # 기준으로 내림차순

    # col번째 값 기준 오름차순, 동일할 경우 다음 경우 첫번째 컬럼 기준으로 내림차순
    data = sorted(data, key = lambda x : (x[col - 1], -x[0]))
    data = data[row_begin - 1 : row_end]
    
    arr = []
    for k in data:
        num = 0
        for s in k:
            num += s % row_begin
        
        # arr이 비어있을 경우 arr에 num을 넣어준다.
        if not arr:
            arr.append(num)
        else:
            arr[0] = arr[0] ^ num
        # XOR 은 ^이다
            
        row_begin += 1
        # 나눠주는 값인 row_begin을 1씩 늘려준다.
    
    
    return arr[0]
