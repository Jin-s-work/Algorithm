day = [0] * 20
money = [0] * 20
ans = [0] * 20
n = int(input())
for i in range(1, n+1):
    a, b = map(int, input().split())
    day[i] = a
    money[i] = b

next = 0
for i in range(n, 0, -1):
    next = day[i] + i
    # next는 day에 i를 더해준 값
    # 다음 날짜를 뜻한다.
    
    if next > n+1:
        ans[i] = ans[i+1]
    # next가 n+1을 넘는 경우 (시간을 넘는 경우) i를 다시 원래대로
    # 즉 지나간다..
    else:
        ans[i] = max(ans[i+1], ans[next] + money[i])
    # ans에는 다음의 ans나 그 next에 그 price를 더하는 경우의 
    # 최대를 ans를 넣는다.
    # 즉 그냥 내려오는 ans[i+1]와 그 전에 오는 ans[next]에 money[i]를 더한 
    # 값을 max로 해서 갱신
    
    # 계속 고민하고 생각해봤는데 뒤에서 찾는 것이 범위 안넘고
    # 더 효과적인 듯
    
print(ans[1])