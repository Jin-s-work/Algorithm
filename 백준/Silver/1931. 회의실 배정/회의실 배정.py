import sys
input = sys.stdin.readline

n = int(input())
arr = []

for k in range(n):
    arr.append(list(map(int, input().split())))
    # a, b = list(map(int, input().split()))
    # arr.append([a, b])

arr.sort(key=lambda x : (x[1], x[0]))
# 두번째를 오름차순한 다음에 첫번째것을 오름차순 정렬

end = 0
ans = 0
for i in range(len(arr)):
    if arr[i][0] < end:
        continue
    # 미리 지정해 둔 끝인 end가 그 다음의 arr[i][0]보다 작을 경우에는
    # 할 필요가 없으므로 continue로 넘어간다.
    
    end = arr[i][1]
    ans += 1 
    
print(ans)