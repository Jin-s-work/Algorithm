def solution(sizes):
    answer = 0
    
    rec = []
    for k in sizes:
        arr = []
        if k[0] <= k[1]:
            arr.append(k[0])
            arr.append(k[1])
        else:
            arr.append(k[1])
            arr.append(k[0])
            
        rec.append(arr)
    
    Maxa = -1
    Maxb = -1
    for k in rec:
        Maxa = max(k[0], Maxa)
        Maxb = max(k[1], Maxb)
    
    
    return Maxa * Maxb