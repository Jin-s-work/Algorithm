from collections import deque

def solution(begin, target, words):
    answer = 0
    
    queue = deque()
    queue.append([begin, 0])
    # 시작단어와 깊이를 넣어준다.
    check = [0 for i in range(len(words))]
    
    while queue:
        word, num = queue.popleft()
        if word == target:
            answer = num
            break
        for i in range(len(words)):
            cnt = 0
            if not check[i]:   # 방문 안했을떄
                for j in range(len(word)):#j는 단어의 길이에 관한 것이므로
                    if word[j] != words[i][j]:
                        cnt += 1
                    # 다른 단어의 개수를 찾는다.
                if cnt == 1:   # 한개인 경우 queue에 넣어준다.
                    queue.append([words[i], num+1])
                    check[i] = 1
    
    
    
    return answer
