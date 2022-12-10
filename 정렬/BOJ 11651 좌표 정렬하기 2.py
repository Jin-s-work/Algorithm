arr = []
n = int(input())
for _ in range(n):
    arr.append(list(map(int, input().split())))
arr.sort(key=lambda x : (x[1], x[0]))

for k in arr:
    print(k[0], k[1])
