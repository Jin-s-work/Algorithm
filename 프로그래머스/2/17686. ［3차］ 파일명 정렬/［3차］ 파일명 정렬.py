def solution(files):
    answer = []
    
    head, number, tail = "", "", ""
    arr = []
    
    for k in files:
        
        for i in range(len(k)):
            if k[i].isdigit():
                head = k[:i]
                number = k[i:]
                
                for j in range(len(number)):
                    if not number[j].isdigit():
                        tail = number[j:]
                        number = number[:j]
                        break
                
                answer.append([head, number, tail])
                head, number, tail = "", "", ""
                break
    
    answer.sort(key = lambda x: (x[0].lower(), int(x[1])))
    
    return [''.join(i) for i in answer]
