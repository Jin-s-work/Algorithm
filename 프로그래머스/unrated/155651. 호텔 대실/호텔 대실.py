
def time_def(string):
    h, m = map(int, string.split(":"))
    return h * 60 + m


def solution(book_time):
    answer = 0
    
    
    arr = sorted([[time_def(k[0]), time_def(k[1]) + 10] for k in book_time])
    
    room = []
    
    for k in arr:
        if not room:
            room.append(k)
            continue
        for idx, bed in enumerate(room):
            if k[0] >= bed[-1]:
                room[idx] = bed + k
                break
        else:
            room.append(k)
        
    
    return len(room)