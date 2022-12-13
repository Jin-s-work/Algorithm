n, k = map(int, input().split())

ans = 0

for hour in range(0, n+1):
    for minute in range(60):
        for sec in range(60):
            if hour % 10 == k or hour // 10 == k or minute % 10 == k or minute // 10 == k or sec % 10 == k or sec // 10 == k:
                ans += 1
    
print(ans)
