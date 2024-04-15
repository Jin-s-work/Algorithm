def solution(genres, plays):
    answer = []
    
    # 속한 노래 많은거 먼저
    # 그 다음은 장르 내에서 많이 재생된 노래
    # 장르내 횟수가 같을 때는 고유 번호가 낮은 노래 먼저
    
    total = {} # 딕셔너리 활용
    
    arr = [[genres[i], plays[i], i] for i in range(len(genres))]
    arr = sorted(arr, key=lambda x: (x[0], -x[1], x[2]))
    # 장르, 재생횟수, 고유번호 이므로
    # 많이 재생될 수록, 같다면 고유번호가 낮을 수록
    # 재생횟수 기준 내림차순, 고유번호 기준 오름차순
    
    for k in arr:
        if k[0] not in total:
            total[k[0]] = k[1]  # 아무것도 없을 경우 k[1]을 할당
        else:
            total[k[0]] += k[1]
    
    total = sorted(total.items(), key = lambda x: -x[1])
    # 재생횟수가 많은 순서대로 (내림차순)
    
    for k in total:
        num = 0
        for t in arr:
            if k[0] == t[0]:    # total과 arr의 장르가 같을 경우 (장르별)
                num += 1        # 장르별로 가장 많이 재생된 노래를
                if num > 2:     # 최대 2까지의 고유번호를 수록한다.
                    break
                else:
                    answer.append(t[2])
    
    
    return answer