def solution(number, k):
    answer = ''
    
    i = 0
    while len(number) - 1 > i and k > 0:
        if number[i] < number[i+1]:
            # 다음의 수가 더 클 경우에는 그 number[i]를 없애주고, 없애주므로 인덱스 줄여주기
            number = number[:i] + number[i+1:]
            if i != 0:
                i -= 1
            k -= 1
        else:
            i += 1
    
    if k > 0:
        return number[:-k]
            
    return number