def solution(n, w, num):
    answer = 0
    
    # 택배 상자의 개수 n, 가로로 놓는 상자의 개수 w, 꺼내는 번호 num
    # w로 나누었을때 몫이 홀수 : 왼쪽
    # w로 나누었을때 몫이 짝수 : 오른쪽
    
    layer = (num - 1) // w
    pos = (num - 1) % w
    
    if layer % 2 == 0:
        col = pos
    else:
        col = w - 1 - pos
        
    total_layer = (n + w - 1) // w
    # 전체 층 수
    cnt = 1
    
    for l in range(layer + 1, total_layer):
        box_layer = min(w, n - l * w)
        if l % 2 == 0:
            if col < box_layer:
                cnt += 1
        else:
            if(w - 1 - col) < box_layer:
                cnt += 1

    # 이게 사실 내가 하려고 한 풀이임
    
    return cnt