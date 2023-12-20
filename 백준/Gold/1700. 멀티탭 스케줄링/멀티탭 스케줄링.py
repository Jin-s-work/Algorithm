import sys
input = sys.stdin.readline

n, k = map(int,input().split())
arr = list(map(int, input().split()))

tab = [0] * (n)    # tab은 멀티탭만큼의 개수인 n개로 해야한다.
                   # 안그러면 elif 0 in tab
ans = 0
Max = 0
cnt = 0

while arr:
    k = arr[0]
    # 처음에 k에 arr[0]을 넣는다.
    
    # 멀티탭에 동일한 제품이 꽂혀있을 경우 제거한다. 그리고 넘어감
    if k in tab:
        arr.remove(k)  # 넣었으므로 사용 순서 리스트에서 없앤다.
        continue       # 없앴으니까 넘어감

    elif 0 in tab:      # tab에 아직 빈자리가 있을 경우 
        tab[tab.index(0)] = k  # 0의 위치에 k를 넣는다. -> 멀티탭 꽂는 것
        arr.remove(k)   # 꽂았으니까 사용 순서 리스트에서 없앤다.
        
    else:      # tab에 k도 없고 0도 없을 경우 즉 빈자리가 없을 경우
        for l in tab:       # tab에서
            if l not in arr:   # arr에 l이 없을 경우에
                cnt = l        # cnt에 l을 넣어주고 break한다.
                break
        # 즉 이것은 멀티탭에 꽂혀있는 제품 중 이후에 꽂는 제품이 없을 때
        
        # 멀티탭에 꽂혀있는 제품 중 가장 나중에 사용하는 제품을 골라서
        # 뽑고 탐색하고 있는 제품을 꽂는다.
            elif arr.index(l) > Max:  # l의 인덱스가 더 클 경우에
                Max = arr.index(l)    # Max에 넣고
                cnt = l              # 이를 cnt에 저장한다.
        
        # 콘센트에 cnt의 위치에 k를 넣어준다.
        # 그리고 순서에서 k를 지워주고
        # Max도 다시 0으로 만든다.
        # 이 과정을 거쳤을때 바뀐 것이므로 ans도 늘려준다.
        tab[tab.index(cnt)] = k
        arr.remove(k)
        Max = 0
        ans += 1
        
print(ans)