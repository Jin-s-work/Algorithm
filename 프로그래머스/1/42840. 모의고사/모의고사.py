def solution(answers):
    answer = []
    
    one = [1, 2, 3, 4, 5]
    two = [2, 1, 2, 3, 2, 4, 2, 5]
    three = [3, 3, 1, 1, 2, 2, 4, 4, 5, 5]
    
    one_num = 0
    two_num = 0
    three_num = 0
    
    for i in range(len(answers)):
        if answers[i] == one[i % len(one)]:
            one_num += 1
        if answers[i] == two[i % len(two)]:
            two_num += 1
        if answers[i] == three[i % len(three)]:
            three_num += 1
    
    arr = [one_num, two_num, three_num]
    
    for idx, num in enumerate(arr):
        if max(arr) == num:
            answer.append(idx + 1)
    
    return answer