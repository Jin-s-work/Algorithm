import sys
input = sys.stdin.readline

n = int(input())

arr = []
for k in range(n):
    a = int(input())
    arr.append(a)

arr.sort(reverse=True)

Max = 0
ans = 0
for i in range(0, len(arr)):
   ans = arr[i] * (i + 1)
   # 제일 큰 것 * (k개의 로프)가 최대일 때를 구한다.
   if ans > Max:
       Max = ans 
       
print(Max)
