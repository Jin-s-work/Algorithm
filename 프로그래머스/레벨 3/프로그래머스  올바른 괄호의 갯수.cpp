def fac(n):
    if n == 1:
        return 1
    return n * fac(n-1)

def solution(n):
    answer = 0
    
    return fac(2*n) / (fac(n+1) * fac(n))

    # 카탈란 수.. 라고 한다.. 수학관데도 들어본듯 안들어본듯
    # (0,0) 에서 (n,n)까지 격자점을 지나는 최단거리의 경로 중에서 직선 y=x  를 넘지 않는 경우의 수
    # 2 // 2 11
    # 3 // 3 (11)1 21 12 111















