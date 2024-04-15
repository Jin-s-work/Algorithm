def solution(genres, plays):
    answer = []
    
    arr = [[genres[i], plays[i], i] for i in range(len(genres))]
    arr = sorted(arr, key=lambda x: (x[0], -x[1], x[2]))
    # 장르, 재생횟수, 고유번호 이므로
    # 많이 재생될 수록, 같다면 고유번호가 낮을 수록
    # 재생횟수 기준 내림차순, 고유번호 기준 오름차순
    
    song = {}
    for k in arr:
        if k[0] in song:
            song[k[0]] += k[1]
        else:
            song[k[0]] = k[1]
            
    song = sorted(song.items(), key = lambda x : -x[1])
    # 재생횟수만큼 내림차순
    
    for k in song:
        num = 0
        for t in arr:
            if k[0] == t[0]:   # 장르가 같을 경우
                num += 1
                if num > 2:
                    break
                else:
                    answer.append(t[2])
                    # 아직 아닐 경우 arr에 있는 인덱스 번호를 넣어준다.
    
        
    
    
    
        
    
    
    return answer