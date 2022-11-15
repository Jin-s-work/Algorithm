from itertools import permutations

def check(user, ban):
    if len(user) != len(ban):
        return False         # 길이 달라도 아님 표시
    else:
        for i, j in zip(user, ban):  # zip으로 user, ban 엮기
            if j == '*':
                continue    # ban에 *가 있는 경우 그냥 continue
            if i != j:
                return False  # user와 ban이 다른 경우 아님 표시
        return True
            

def solution(user_id, banned_id):
    answer = []
    
    for i in permutations(user_id, len(banned_id)):
        cnt = 0
        
        # user_id를 permutation으로 banned_id만큼 돌려서 i로 해줌
        # banned_id가 2개일 경우 ('frodo', 'fradi'), ('frodo', 'crodo'), ... 이런식
        
        for a, b in zip(i, banned_id):
            if check(a, b):
                cnt += 1       # true일 경우에 개수를 늘려준다.
        if cnt == len(banned_id):      # 찾는 banned_id와 길이가 같고
            if set(i) not in answer:   # i를 set으로 중복검사하였을때 answer에 없으면
                answer.append(set(i))  # set(i)를 넣어준다.
            # 순서에 관계없이이므로 set으로 변환 후 집어넣는다.
    
    return len(answer)
