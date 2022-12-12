
import sys
input = sys.stdin.readline
arr = []
n = int(input())
for _ in range(n):
    arr.append(int(input()))

Sum = sum(arr)
print(round(Sum / n))

arr.sort()
print(arr[int((n-1) / 2)])

cnt = dict()
for k in range(1, n+1):
    cnt[k] = []

Max = 1
count = 1
for i in range(1, n):
    if arr[i] == arr[i-1]:
        count += 1
        # 같은 게 있을 경우 count를 늘려준다.
    else:  # 다른 게 나올 경우 개수에 대해서 arr의 값을 넣어준다.
        cnt[count].append(arr[i-1])
        if Max < count:
            Max = count
            # 최대를 넘으면 그 최대 count를 Max에 넣어줌
        count = 1
    if i == n-1:
        cnt[count].append(arr[i])
        if Max < count:
            Max = count
        # 끝날 경우 그 값을 넣어준다.
if n == 1:
    cnt[1].append(arr[0])

cnt[Max].sort()
if len(cnt[Max]) == 1:
    print(cnt[Max][0])   # 최빈값이 1개일 때 1개 출력
else:
    print(cnt[Max][1])   # 아닐 경우 두번째 작은 값을 출력
    
print(arr[-1] - arr[0])
