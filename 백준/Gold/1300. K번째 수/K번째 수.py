

n = int(input())
k = int(input())

# k는 min(10^9, n^2)보다 작거나 같은 수
# a[i][j]= i*j라고 했을때 이를 오름차순 정렬해서 B[k]를 구하라

# n*n까지 중 i*j를 넣어서 k번째 수를 구하는 것이다.
# 포인트 : x이하의 값이 몇개인지 계산하기
# i*j의 형태이니까 수에서 i를 나누면서 간다.

def find(num):
    total = 0
    for i in range(1, n + 1):
        total += min(num // i, n)
        # num // i의 몫이 n을 넘으면 안되니까 min으로 한다.
    return total
# num이하의 값이 몇개가 올 수 있는지를 그때그때 계산한다.
# n자체는 10만 이하라 for문 하나는 괜찮다.

left = 1
right = 1000000000
ans = right
while left <= right:
    mid = (left + right) // 2
    if find(mid) >= k:
        ans = min(ans, mid)
        right = mid - 1
    else:
        left = mid + 1

print(ans)