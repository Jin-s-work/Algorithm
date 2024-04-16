def solution(n, words):
#     used_words = set()  # 이전에 사용된 단어를 저장할 집합
#     last_char = words[0][0]  # 첫 단어의 첫 글자로 시작해야 하므로 초기화

#     for i, word in enumerate(words):
#         # 현재 단어의 첫 글자가 이전 단어의 마지막 글자와 다르거나
#         # 현재 단어가 이미 사용되었거나
#         if word in used_words or last_char != word[0]:
#             # 현재 단어를 말한 사람의 번호와 차례를 계산하여 반환
#             return [(i % n) + 1, (i // n) + 1]
        
#         # 현재 단어를 사용된 단어 집합에 추가
#         used_words.add(word)
#         # 마지막 문자를 업데이트
#         last_char = word[-1]

#     # 모든 단어를 정상적으로 사용했다면 [0, 0] 반환
#     return [0, 0]

    answer = []
    flag = False
    used_words = set()  # 중복 검사용 집합
    last_char = words[0][0]  # 첫 단어의 첫 글자로 시작하므로 초기화

    for i in range(len(words)):
        word = words[i]
        # 첫 단어가 아니고, 단어가 이미 사용되었거나, 마지막 글자와 첫 글자가 일치하지 않는 경우
        if (word in used_words or (i != 0 and words[i-1][-1] != word[0])):
            answer.append((i % n) + 1)  # 사람 번호
            answer.append((i // n) + 1)  # 해당 사람의 차례
            flag = True
            break
        used_words.add(word)  # 사용된 단어에 추가

    if not flag:
        answer.append(0)
        answer.append(0)

    return answer