

n, s = map(int, input().split())
arr = list(map(int, input().split()))

import sys
ans = sys.maxsize

left, right = 0, 0
total = arr[0]

while right < n:

    if total >= s:
        ans = min(ans, right - left + 1)
        total -= arr[left]
        left += 1
    else:
        right += 1
        if right < n:
            total += arr[right]

if ans == sys.maxsize:
    print(0)
else:
    print(ans)