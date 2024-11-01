

k, n = map(int, input().split())

arr = []
for i in range(k):
    a = int(input())
    arr.append(a)

ans = 0
def cal(num):
    cnt = 0
    for k in arr:
        cnt += (k // num)

    return cnt

left = 1
right = max(arr)
while left <= right:
    mid = (left + right) // 2

    if cal(mid) >= n:
        left = mid + 1
        ans = max(ans, mid)
    else:
        right = mid - 1

print(ans)