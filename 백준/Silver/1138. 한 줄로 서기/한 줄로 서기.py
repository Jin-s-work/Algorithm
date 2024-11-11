


n = int(input())

arr = list(map(int, input().split()))

ans = [0] * (n)


for i in range(n):
    cnt = arr[i]
    # 왼쪽부터 빈 자리를 찾으면 조건을 만족하는 위치를 찾는다.
    for j in range(n):
        # 빈 자리인 경
        if ans[j] == 0:
            if cnt == 0:
                ans[j] = i + 1
                break
            cnt -= 1
            # 빈 자리일 경우에 cnt를 줄여나가다가 맞는 자리일 때 -> cnt == 0 
            # 조건에 만족하는 위치를 찾으면서 카운트를 줄여나간다.


for k in ans:
    print(k, end = " ")

