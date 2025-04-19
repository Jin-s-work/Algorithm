
n, l = map(int, input().split())
arr = list(map(int, input().split()))

# 최소 좌우로 0.5씩
arr.sort()

ans = 0
idx = 0
while idx < n:
    start = arr[idx]
    end = start - 0.5 + l

    idx += 1
    while idx < n and arr[idx] < end:
        idx += 1

    ans += 1

print(ans)