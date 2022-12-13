a, b, c, m = map(int, input().split())
# 쌓이는 피로 a 처리하는 일 b, 피로도 c 줄어듬
ans = 0
work = 0
for h in range(24):
    if ans + a > m:
        if ans - c < 0:
            ans = 0
        else:
            ans -= c
    else:
        ans += a
        work += b
print(work)
