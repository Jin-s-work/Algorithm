
from collections import deque

def solution(begin, target, words):
    answer = 0
    
    q = deque()
    q.append([begin, 0])
    check = [0] * len(words)
    
    while q:
        word, num = q.popleft()
        
        if word == target:
            answer = num
            break
        
        for i in range(len(words)):
            cnt = 0
            if not check[i]:
                for j in range(len(word)):
                    if word[j] != words[i][j]:
                        cnt += 1
                    # 안맞는 개수를 그때그때 세준다.
                    
                if cnt == 1:
                    q.append([words[i], num + 1])
                    check[i] = 1
                # 안맞는 개수가 한개이면, 그 단어를 q에 넣어놓는다. (BFS)
    
    return answer