import sys
input = sys.stdin.readline

n = int(input())

arr = []
for _ in range(n):
    a, b, c, d = map(int, input().split())
    arr.append([100 * a + b, 100 * c + d])
    
arr.sort()
# 꽃 피는 날짜, 꽃이 지는 날짜 순으로 오름차순

end_date = 301
ans = 0

while (arr):
    # end_date가 1201을 넘어버리거나 시작 날짜가 end_date보다 커져버리면 break
    if (end_date >= 1201 or arr[0][0] > end_date):
        break
    
    tmp_end = -1
    
    for _ in range(len(arr)):
        if arr[0][0] <= end_date:
            if tmp_end <= arr[0][1]:
                tmp_end = arr[0][1]
        # end_date보다 전이고 tmp_end도 끝나는 시간보다 작을 경우 넣어준다.
        
            arr.remove(arr[0])
        # 썼으므로 지우기     
        else:
            break
        # 만약 시작 날짜가 end_date보다 뒤면 break한다.
    
    end_date = tmp_end
    ans += 1

if end_date < 1201:
    print(0)
else:
    print(ans)
