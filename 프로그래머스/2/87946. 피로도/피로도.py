answer = 0
n = 0
check = []

def DFS(k, num, dungeons):
    global answer
    if num > answer:
        answer = num
    # num이 원래의 answer보다 클 경우 갱신한다.
        
    for i in range(n):
        if k >= dungeons[i][0] and not check[i]:
            check[i] = 1
            DFS(k - dungeons[i][1], num+1, dungeons)
            check[i] = 0
    # 0~(n-1)에 대해서 k가 최소 피로도 보다 크고 방문하지 않았을 경우에만
    # check에 대해 1로 체크해주고, 피로도를 줄이고, 연산한 대로 한다.

def solution(k, dungeons):
    global n, check
    n = len(dungeons)
    check = [0] * n
    DFS(k, 0, dungeons)
    
    return answer