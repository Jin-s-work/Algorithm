

n, m = map(int, input().split())

arr = list(map(int, input().split()))

s = [0, arr[0]]
for i in range(1, len(arr)):
    s.append(arr[i] + s[i])

# [0 5 9 12 14 15]
for _ in range(m):
    i, j = map(int, input().split())
    print(s[j] - s[i-1])