answer = 9
def solution(N, number):

    def DFS(n, num, cnt, now):
        global answer
        if cnt >= 9:
            return
        # 최솟값이 8을 넘으면 끝
        if now == num:
            answer = min(answer, cnt)
            return
        # now와 원하는 num이 같을 경우 답을 구하고 리턴
        
        tmp = 0
        # 이미 cnt번 썼으므로 9에서 cnt만큼을 뺀 만큼 - 1 까지 i가 가능함
        # 즉 8 - cnt + cnt + 1 = 9 이므로 두번째가 9일때까지만 할 수 있다.
        for i in range(0, 9 - cnt):
            tmp = tmp * 10 + n
            # 5, 55, 555 이런 경우로도 쓸 수 있으므로 tmp를 저장해서 10을 곱하고 일의 자리 해결하기
            
            DFS(n, num, cnt + i + 1, now + tmp)
            DFS(n, num, cnt + i + 1, now - tmp)
            DFS(n, num, cnt + i + 1, now * tmp)
            DFS(n, num, cnt + i + 1, now // tmp)
            # 각각 사칙 연산으로 들어간다.

    
    DFS(N, number, 0, 0)
    # 최솟값이 8보다 크면 -1리턴
    if answer == 9:
        return -1
    
    
    return answer