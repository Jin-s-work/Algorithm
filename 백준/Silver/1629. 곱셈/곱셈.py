

a, b, c = map(int, input().split())

# a를 b번 곱하고 c로 나눈 나머지

# a를 (b//2) 번 곱한거 * 2 해주면
# 반으로 줄어서 O(logb)가 된다.
# 홀수일 경우에는 한번 더 곱하면 된다.

def func(a, b):
    if b == 1:
        return a % c
    num = func(a, b // 2)
    if b % 2 == 0:
        return (num * num) % c
    else:
        return (num * num * a) % c

print(func(a, b))

# 시간복잡도가 O(logb)
# 재귀적으로 문제를 나누어서 푼다.