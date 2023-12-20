import sys
input = sys.stdin.readline

n = int(input())

arr = []
for _ in range(n):
    a = int(input())
    arr.append(a)

ans = 0
for i in range(len(arr)-1, 0, -1):
    if arr[i-1] < arr[i]:
        continue
    else:
        ans += (arr[i-1] - arr[i]) + 1
        arr[i-1] = arr[i] - 1
  
print(ans)      
