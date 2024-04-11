def solution(phone_book):
    answer = True
    
    hash_map = {}
    for phone_number in phone_book:
        hash_map[phone_number] = 1
    
    for phone_number in phone_book:
        tmp = ""
        for number in phone_number:
            tmp += number
            if tmp in hash_map and tmp != phone_number:
                answer = False
            # 더해가며 만든 tmp가 hash map에 있는데 완전 똑같은 경우가 아닐 경우에 False
    
     
    return answer