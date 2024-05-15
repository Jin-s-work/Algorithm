def solution(book_time):
    answer = 0
    
    arr = []
    for k in book_time:
        tmp = []
        num1 = int(k[0][:2]) * 60
        num1 += int(k[0][3:])
        tmp.append(num1)
        num2 = int(k[1][:2]) * 60
        num2 += int(k[1][3:]) + 10
        tmp.append(num2)
        arr.append(tmp)
    
    arr.sort(key = lambda x : x[0])
    
    rooms = []
    for k in arr:
        if not rooms:
            rooms.append(k)
            continue
        for idx, room in enumerate(rooms):
            if k[0] >= room[-1]:
                rooms[idx] = room + k
                break
        else:
            rooms.append(k)
    
    
    return len(rooms)