import sys
input = sys.stdin.readline

n = int(input())

arr = []
for _ in range(n):
    a, b = map(int, input().split())
    arr.append([a, b])

arr.sort(key=lambda x : (x[0], -x[1]))

ans = 0
start = arr[0][0]
end = arr[0][1]
for k in arr:
    if k[1] > end:
        if k[0] > end:
            ans += (end - start)
            start = k[0]
            end = k[1]
        else:
            end = k[1]
ans += (end - start)

print(ans)
