def solution(weights):
    answer = 0
    
    check = [-1 for _ in range(4010)]
    arr = [-1 for _ in range(1010)]
    
    num = 0
    for i in range(len(weights)):
        arr[weights[i]] += 1
        num += arr[weights[i]]
        same_num = arr[weights[i]]
        # 이 과정에서 같은 것이 있다면 1 늘려서 추가해준다.
        # 이렇게 배열을 사용하면 이중포문 안써도 되서 시간 초과 방지
        
        # 2, 3, 4 
        # 1:2, 2:3, 3:4 이므로
        for j in range(2, 5):
            # 비율에 대해서 1을 더해준다.
            check[weights[i] * j] += 1
            num += (check[weights[i] * j] - same_num)
            # 만약 check가 1번밖에 안가는 경우에는 num에 안더해주는 것이다.
    
    return num

# 탑승한 사람의 무게와 시소 축과 좌석 간의 거리의 곱이 같을때 짝꿍



