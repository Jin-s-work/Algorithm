import sys
# sys.setrecursionlimit(10**6)
input = sys.stdin.readline


n, r, c = map(int, input().split())

ans = 0
def zero(a, b, n):
    global ans
    if a == r and b == c:
        print(ans)
        return
    # a와 b가 r,c에 도착할 경우 print하고 return한다.
    
    if n == 1:
        ans += 1
        return
    # 1일 경우에는 한번만 하고 끝낸다.
    
    if not (a <= r and r < a + n and b <= c and c < b + n):
        ans += n * n
        return
    # 범위 밖을 벗어난 경우 n*n을 더해준다.
    
    zero(a, b, n//2)
    zero(a, b + n//2, n//2)
    zero(a + n//2, b, n//2)
    zero(a + n//2, b + n//2, n//2)
    # 이동한 만큼 각자 하기 
    # |-> 
    # 각자 네개의 곳에서 출발해서 재귀를 이어가기

zero(0,0,2**n)

# 4 7 2^3
# 4 7+2^3, 2^3
# 4+2^3, 7, 2^3
# 4+2^3, 7+2^3, 2^3
