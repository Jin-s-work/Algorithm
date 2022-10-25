def solution(relation):
    answer = 0
    
    # 유일하게 가지고 있으면 후보 키가 될 수 있다.
    # - 모든 튜플에 대해 유일하게 식별되어야 한다.
    # - 유일성을 가진 키를 구성하는 속성 중 하나라도 제외되는 경우 유일성이 깨짐
    #   즉, 모든 튜플을 유일하게 식별하는 데 꼭 필요한 속성들로만 구성되어야 한다.
    
    # 여기서 학번은 유일하기에 후보 키가 될 수 있다.
    # 이름은 같은 이름을 사용하는 학생이 있어서 안된다.
    # 하지만, [이름, 전공]을 함께 사용하면 모든 튜플을 유일하게 식별 할 수 있으므로 후보키가 가능
    # [이름, 전공, 학년]도 물론 모든 튜플을 식별가능하지만, 최소성을 만족하지 않으므로
    # 학번, [이름, 전공] 두 가지가 된다.
    
    from itertools import combinations
    n = len(relation)
    m = len(relation[0])
    
    # 전체 조합을 arr에 저장한다.
    arr = []
    for i in range(1, m+1):
        arr.extend(combinations(range(m), i))
        # append는 새로 리스트 자체를 넣어주지만 extend는 똑같은 형태로 이어준다.
        # 여기서는 이와 같이 하면서 columns의 가능한 모든 인덱스 조합을 구한다.
        # arr는 예제에 따르면 [[0],[1],[2],[3],[0,1],[0,2],[0,3],[1,2],[1,3],[2,3],[0,1,2],[0,1,3],[0,2,3],[1,2,3],[0,1,2,3]] 와 같이 나온다.
    check = []
    for k in arr:
        tmp = [tuple([item[i] for i in k]) for item in relation]
        if len(set(tmp)) == n:  # 이렇게 중복을 제거한 길이가 n일경우
            check.append(k)     # 되는 것이므로 check에 넣어줌
        # 인덱스 조합을 item에 해당하는 속성 값을 추출하여 tuple에 담아
        # 리스트로 모아논 값이 row의 길이와 같은지를 체크했다.
    
    # 최소성을 찾는다.
    answer = set(check)
    for i in range(len(check)):
        for j in range(i+1, len(check)):
            if len(check[i]) == len(set(check[i]) & set(check[j])):
                answer.discard(check[j])
    # check에 대해서 이중포문으로 탐색하며 &를 하여 (교집합) 원래의 check[i] 길이와 같을 경우
    # discard를 통하여 check[j]를 제거해주었다..
    
    return len(answer)   # 답의 개수를 선택한다.
