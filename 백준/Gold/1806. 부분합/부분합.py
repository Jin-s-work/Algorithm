


n, s = map(int, input().split())
arr = list(map(int, input().split()))

num = 0
left, right = 0, 0
ans = 1000000

while left <= right:
    if num >= s:
        ans = min(ans, right - left)
        num -= arr[left]
        left += 1
    elif right == n:
        break
    else:
        num += arr[right]
        right += 1
# 일반적인 이분탐색 + 부분합
# 처음 num을 0으로 시작했기 때문에 움직일때 거기의 인덱스의 arr를 더해주고 인덱슬르 옮긴다.
# 합보다 클 경우에는 left 값을 빼주고 옮기고
# 합보다 작은 경우에는 right를 더해주고, right도 옮겨준다.


if ans == 1000000:
    print(0)
else:
    print(ans)