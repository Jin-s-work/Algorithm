def solution(s):
    answer = []
    
    # 튜플이라고 따로 뭘 해야하는 것이 아니라 문자열 취급을 해준다.
    s = s[2:-2]
    s = s.split("},{")
    s.sort(key = len)
    # 길이에 따라서 sort
    
    for k in s:
        ans = k.split(",")
        for i in ans:
            if int(i) not in answer:
                answer.append(int(i))
    
    return answer
