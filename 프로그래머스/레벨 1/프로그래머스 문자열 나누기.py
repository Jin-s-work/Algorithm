def solution(s):
    answer = 0
    
    idx = 0
    x = s[0]
    for i in range(len(s)-1):
        if s[i] == x:
            idx += 1     # i를 늘려가며 비교해주면서 같을 경우 idx 늘려준다.
        else:
            idx -= 1     # 다를 경우 줄여준다..
        
        if idx == 0:     # 개수가 같아 0이 될경우 answer를 늘려주고, x를 넘어가서 시작
            answer += 1
            x = s[i+1]
        # idx가 0일 때 새로고침하므로, idx는 초기화안해줘도 된다.
    
    # 나누는 경우의 수에서 한 글자와 나머지 글자들의 개수가 같아야 하므로 위와 같이 하는게 맞다..
    # 인덱스를 올라가며 갱신해주는 것..
    
    return answer+1   # 앞의 answer도 증가시켜주어야 한다.
