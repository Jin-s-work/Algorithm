from itertools import combinations

def solution(n, q, ans):
    answer = 0
    
    # 전략 : 1~n까지 모든 조합을 5개씩 뽑아서 대조한다.
    # 여기에서 set으로 해서 나온 값이 ans와 다를 경우 넘어간다.
    for comb in combinations(range(1, n + 1), 5):
        check = True
        for query, expect in zip(q, ans):
            # 겹친 개수를 세준다. 
            # (set(query) & set(comb)를 하면 겹친 숫자들이 나온다.)
            if len(set(query) & set(comb)) != expect:
                check = False
                break
        if check:
            answer += 1
        
    
    return answer