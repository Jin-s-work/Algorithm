import sys
input = sys.stdin.readline

t = int(input())


for _ in range(t):
    ans = 0
    
    n = int(input())
    arr = list(map(int, input().split()))
        
    arr.reverse()
    # 거꾸로 해서 다음 값들이 작으면 더해버리기
    Max = arr[0]

    for i in range(1, n):
        if Max < arr[i]:
            Max = arr[i]
            continue
        # Max 보다 클 경우에 저장하고 넘어간다. 이 경우에는 계산 안함
        
        ans += Max - arr[i]
    
    print(ans)