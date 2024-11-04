


an, bn = map(int, input().split())
a = list(map(int, input().split()))
b = list(map(int, input().split()))

a.sort()
b.sort()

ans = []
def binary(arr, num):
    left = 0
    right = len(arr) - 1
    while left <= right:
        mid = (left + right) // 2
        if arr[mid] == num:
            return True
        elif arr[mid] < num:
            left = mid + 1
        elif arr[mid] > num:
            right = mid - 1
    return False

for k in a:
    if not binary(b, k):
        ans.append(k)

ans.sort()
if len(ans) == 0:
    print(0)
else:
    print(len(ans))
    for k in ans:
        print(k, end = " ")