def solution(phone_book):
    answer = True
    
    dic = {}
    for k in phone_book:
        dic[k] = 1
    
    for phone in phone_book:
        st = ""
        for num in phone:
            st += num
            if st in dic and st != phone:
                answer = False
    
    
    
    return answer