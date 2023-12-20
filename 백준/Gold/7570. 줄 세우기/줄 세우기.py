import sys
input = sys.stdin.readline

n = int(input())

arr = list(map(int, input().split()))
arr.insert(0,0)
# 인덱스와 맞추어주기위해 제일 앞에 0을 넣어준다.

idx_arr = [0] * (n+1)
Max = -1
cnt = 0

for i in range(1, len(arr)):
    idx_arr[arr[i]] = i
# idx_arr의 값에 어떤 값이 어떤 위치인지 적어주기
# idx_arr[3] = 1 ,,, 3은 1의 위치에 있다는 뜻

for i in range(n):
    # 즉 그러니까 여기에서는 위치를 비교하는 것이다. 
    # 값이 한개 차이인데 더 뒤에 있다면 cnt를 증가시키는 것..
    # 즉 여기에서 cnt는 이동할 필요가 없는 수이다.
    if idx_arr[i] < idx_arr[i+1]:
        cnt += 1
        # 이렇게 해나가다가 Max보다 커지면 갱신한다.
        # 이동할 필요가 없는 최대의 수가 늘어날 수록 갱신
        if Max < cnt:
            Max = cnt
    else:
        cnt = 1
    
print(n - Max)
# 전체 개수 에서 이동할 필요가 없는 수를 빼주면 이동해야 하는 수