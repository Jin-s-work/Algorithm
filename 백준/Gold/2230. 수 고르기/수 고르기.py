

n, m = map(int, input().split())
arr = []

for _ in range(n):
    a = int(input())
    arr.append(a)

arr.sort()

import sys
ans = sys.maxsize
left, right = 0, 0
while right < n:
    if left >= n:
        break
    if arr[right] - arr[left] >= m:
        ans = min(ans, arr[right] - arr[left])
        left += 1
    else:
        right += 1

print(ans)
