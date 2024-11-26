

t = int(input())

def binary(arr, num):
    left = 0
    right = len(arr) - 1
    cnt = 0
    while left <= right:
        mid = (left + right) // 2
        if arr[mid] >= num:
            right = mid - 1
        else:
            # x가 mid(가운데)보다 더 클 경우에는
            # x보다 작은 값의 개수가 mid + 1 (0부터 시작하므로)
            cnt = mid + 1
            left = mid + 1
    return cnt

# A는 자기보다 크기가 작은 먹이만 먹을 수 있다.
for T in range(t):
    n, m = map(int, input().split())
    a = list(map(int, input().split()))
    b = list(map(int, input().split()))
    b.sort()
    ans = 0

    for k in a:
        ans += binary(b, k)


    print(ans)