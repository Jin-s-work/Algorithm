

n = int(input())
k = int(input())
arr = list(map(int, input().split()))

arr.sort()
# 1 3 6 6 7 9
dist = []
for i in range(1, len(arr)):
    dist.append(arr[i] - arr[i-1])

dist.sort(key=lambda x : -x)
# 2 3 0 1 2
# 3 2 2 1 0

ans = 0
for i in range(k-1, len(dist)):
    ans += dist[i]

print(ans)