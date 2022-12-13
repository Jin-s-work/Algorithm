n = int(input())

ans = 0
for k in range(1, n+1):
    arr = list(map(int, str(k)))
    # 값들을 리스트로 만들어줌
    ans = k + sum(arr)
    
    if ans == n:
        print(k)
        break
    if k == n:
        print(0)
