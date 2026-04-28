def solution(message, spoiler_ranges):
    answer = 0
    
    # 단어 일부에 스포일러 방지가 적용되도 단어 전체를 스포일러 방지 단어로
    # 스포 방지 구간을 클릭해 단어의 모든 문자가 공개되었을 때 조건을 만족하면 중요한 단어
    
    # 1. 스포 방지 단어
    # 2. 메시지 스포 방지 구간 아닌 구간에 등장한 적이 없어야 한다.
    # 3. 이전에 공개된 단어와 중복되지 않아야한다.
    # 4. 여러 단어가 동시에 공개되면, 왼쪽부터 순서대로 하나씩 중요한 단어인지 판단
    
    # 풀이하려고 하는 방법
    # 인덱스에 알맞은 단어들을 넣어놓기
    # 스포 단어가 아닌 부분들을 따로 만들어놓고 in으로 확인하기
    
    word = []
    tmp = ""
    start = 0
    end = 0
    for (idx, st) in enumerate(message):
        if st == " ":
            word.append((start, idx-1, tmp))
            tmp = ""
            start = idx + 1
        else:
            tmp += st
    word.append((start, idx-1, tmp))
    # 이제 word에는 (start, end, word) 식으로 들어가있다.
    
    not_spoiler = set()
    spoiler_range = [[] for _ in range(len(spoiler_ranges))]
    for w in word:
        overlap = []
        
        for idx, k in enumerate(spoiler_ranges):
            if w[0] <= k[1] and w[1] >= k[0]:
                overlap.append(idx)
        
        # 스포 구간과 안겹치면 일반 단어
        if not overlap:
            not_spoiler.add(w[2])
        else:
            last = overlap[-1]
            spoiler_range[last].append((w[0], w[2]))
            # 여러 스포 구간에 걸치면 마지막에 완전히 공개된다.
        
    spoiler = []
    for arr in spoiler_range:
        arr.sort()
        for _, w in arr:
            spoiler.append(w)
    
    ans = set()
    for s in spoiler:
        if s not in not_spoiler and s not in ans:
            ans.add(s)
    
    return len(ans)
    
#     spoiler = []
#     not_spoiler = []
#     for k in spoiler_ranges:
#         for w in word:
#             if (w[0] <= k[1] and w[1] >= k[0]) and (w[2] not in spoiler):
#                 spoiler.append(w[2])
#     for w in word:
#         if w[2] not in spoiler:
#             not_spoiler.append(w[2])
    
#     ans = []
#     for s in spoiler:
#         if s not in not_spoiler:
#             ans.append(s)
            
    # return len(ans)
    
    
    
    