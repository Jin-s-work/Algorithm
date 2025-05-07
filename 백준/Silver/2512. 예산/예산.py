

n = int(input())
arr = list(map(int, input().split()))
m = int(input())

# 정해진 총액 이하에서 가능한 최대의 총 예산
# 상한값에 따라서 합을 맞출 수 있다. -> 이분 탐색으로 상한값 바꾸기

ans = 0
def func(num):
    s = 0
    for k in arr:
        if k >= num:
            s += num
        else:
            s += k
    if s <= m:
        return True
    else:
        return False

left = 1
right = max(arr)
while left <= right:
    mid = (left + right) // 2
    if func(mid):
        left = mid + 1
        ans = max(ans, mid)
    else:
        right = mid - 1

print(ans)