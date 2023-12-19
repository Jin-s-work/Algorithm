import sys
input = sys.stdin.readline

n, m = map(int, input().split())

arr = list(map(int, input().split()))


while m:
    arr.sort()
    a = arr[0]
    b = arr[1]
    arr[0] = a + b
    arr[1] = a + b
    m -= 1
    
print(sum(arr))
    

