

n = int(input())
arr = list(map(int, input().split()))
arr.sort()

# 안테나는 집이 위치한 곳에만 설치할 수 잇다 -> 중앙 값

ans = 0
if len(arr) % 2 == 0:
    mid = (len(arr) // 2) - 1

    ans1, ans2 = 0, 0
    for k in arr:
        ans1 += abs(k - arr[mid])
    for k in arr:
        ans2 += abs(k - arr[mid + 1])
    if ans1 > ans2:
        ans = mid + 1
    else:
        ans = mid
else:
    mid = len(arr) // 2
    ans = mid

print(arr[ans])