def solution(n, costs):
    answer = 0
    
    costs.sort(key=lambda x : x[2])
    arr = set([costs[0][0]])
    
    while len(arr) != n:
        for v in costs:
            if v[0] in arr and v[1] in arr:
                continue
            if v[0] in arr or v[1] in arr:
                arr.update([v[0], v[1]])
                answer += v[2]
                break
    
    
    return answer


