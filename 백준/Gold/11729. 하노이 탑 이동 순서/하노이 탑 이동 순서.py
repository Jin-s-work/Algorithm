import sys
# sys.setrecursionlimit(10**6)
input = sys.stdin.readline

n = int(input())

def hanoi(start, mid, end, n):
    if n == 1:
        print(start, end)
    else:
        hanoi(start, end, mid, n-1)
        # end와 mid 바꾸기
        print(start, end)
        hanoi(mid, start, end, n-1)
        # start와 mid 바꾸기

# n개의 원판을 옮길때에는
# 1. n-1개의 원판 첫번째에서 두번째로
# 2. 마지막 원판을 첫번째에서 세번째로
# 3. n-1개의 원판 두번째에서 세번째로

print(2**n - 1)

hanoi(1, 2, 3, n)

