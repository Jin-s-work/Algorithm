import sys
n = int(input())
arr = list(map(int, input().split()))
arr.sort()
m = int(input())
arr2 = list(map(int, input().split()))

def binary(k, arr, start, end):
    if start > end:
        return 0
    
    mid = (start + end) // 2
    # 가운데를 항상 갱신
    if k == arr[mid]:    # 같은 게 나올 경우 1을 리턴
        return 1
    elif k < arr[mid]:   # 더 작을 경우 왼쪽 탐색
        return binary(k, arr, start, mid-1)
    else:              # 더 클 경우 오른쪽 탐색
        return binary(k, arr, mid+1, end)
    
for k in arr2:
    start = 0
    end = len(arr) - 1
    print(binary(k, arr, start, end))

