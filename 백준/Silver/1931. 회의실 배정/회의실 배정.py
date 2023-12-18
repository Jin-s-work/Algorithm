n = int(input())
arr = []
for _ in range(n):
    arr.append(list(map(int, input().split())))

# x[1] 즉 끝나는 시간을 먼저 정렬해줌으로서 끝나는 시간으로 정렬
arr.sort(key = lambda x : (x[1], x[0]))
end = 0
ans = 0
for i in range(len(arr)):
    if arr[i][0] < end:
        continue   
    # end가 arr[i][1] 즉 끝나는 시간보다 작을 경우에는 그냥 넘어감
    
    end = arr[i][1]   # 끝나는 시간을 end로 설정
    ans += 1
    # 아닐 경우 end를 갱신해주고 답 증가시킴
    
print(ans)