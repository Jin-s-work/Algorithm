


n, l = map(int, input().split())
# n개의 물웅덩이, 길이가 l개인 널빤지

last = 0
arr = []
for i in range(n):
    a, b = map(int, input().split())
    arr.append((a, b))
    last = max(last, b)

arr.sort(key=lambda x : x[0])

ans = 0
now = arr[0][0]
for start, end in arr:
    if now < start:
        now = start

    if (end - now) % l == 0:
        ans += (end - now) // l
        now = ((end - now) // l) * l
    else:
        ans += ((end - now) // l) + 1
        now += (((end - now) // l) + 1) * l


print(ans)