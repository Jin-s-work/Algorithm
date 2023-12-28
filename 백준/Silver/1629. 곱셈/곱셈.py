import sys
# sys.setrecursionlimit(10**6)
input = sys.stdin.readline


a, b, c = map(int, input().split())

def multiple(a, b, c):
    if b == 1:
        return a % c
    else:
        # 너무 횟수가 클 수 있으므로 2로 나누어서 두번에 걸쳐서 하는 것이다.
        # 홀수 일 경우에는 한번 덜 한뒤에 한번더 해주는 것
        num = multiple(a, b//2, c)
        if b % 2 != 0:
            return (((num * num) % c) * a) % c
        else:
            return (num * num) % c
    
# (a*b) % c = (a % c) * (b % c) % c 
# 를 이용하는 것이다.
    
print(multiple(a, b, c))

