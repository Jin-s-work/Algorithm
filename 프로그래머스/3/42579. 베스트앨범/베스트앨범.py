def solution(genres, plays):
    answer = []
    
    # 속한 노래 많은 장르
    # 장르 내 많이 재생된 노래
    # 재생 횟수가 같으면 고유번호 낮은 노래
    
    arr = [[genres[i], plays[i], i] for i in range(len(genres))]
    arr = sorted(arr, key=lambda x : (x[0], -x[1], x[2]))
    # 장르, 재생횟수, 고유번호
    
    dic = {}
    for k in arr:
        if k[0] not in dic:
            dic[k[0]] = k[1]
        else:
            dic[k[0]] += k[1]
    
    dic = sorted(dic.items(), key = lambda x : -x[1])
    
    for k in dic:
        num = 0
        for t in arr:
            if k[0] == t[0]:
                num += 1
                if num > 2:
                    break
                else:
                    answer.append(t[2])
    
    
    
    return answer