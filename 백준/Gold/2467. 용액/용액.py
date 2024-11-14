

n = int(input())
arr = list(map(int, input().split()))


# 같은 양의 두 용액을 혼합한 용액의 특성값 = 혼합에 사용된 각 용액의 특성값
# 두 용액을 혼합해 0에 가장 가까운 용액
import sys
left = 0
right = len(arr) - 1
Min = sys.maxsize
a, b = 0, 0
while left < right:
    if abs(arr[left] + arr[right]) < Min:
        a, b = arr[left], arr[right]
        Min = abs(arr[left] + arr[right])

    if arr[left] + arr[right] > 0:
        right -= 1
    elif arr[left] + arr[right] < 0:
        left += 1
    else:
        break


print(a, b)