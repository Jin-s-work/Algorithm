

n, k = map(int, input().split())
arr = list(map(int, input().split()))

ans = 0
tap = []
for i in range(len(arr)):
    if arr[i] in tap:
        continue
    # 이러한 방식으로 해야 다 차있는데, 이미 tap에 있는 경우를 고려가능하다.
    # tap에 있는 경우에는 무조건 그냥 continue
    if len(tap) < n:
        tap.append(arr[i])
    else:
        last_use = -1
        target = -1
        for plugged in tap:
            if plugged not in arr[i:]:
                target = plugged
                break
            else:
                # 뒤에 있는 경우에 가장 마지막에 쓰이는 것을 찾아서
                # 그것을 빼고 새로운 것을 넣어준다.
                idx = arr[i:].index(plugged)
                if idx > last_use:
                    last_use = idx
                    target = plugged
        tap.remove(target)
        tap.append(arr[i])
        ans += 1

print(ans)
