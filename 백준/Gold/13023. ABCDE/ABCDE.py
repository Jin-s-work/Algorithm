

n, m = map(int, input().split())

arr = [[] for _ in range(n)]
for _ in range(m):
    a, b = map(int, input().split())
    arr[a].append(b)
    arr[b].append(a)

check = [0] * (n + 1)

def DFS(num, depth):
    if depth == 4:
        print(1)
        exit()

    check[num] = True
    for next in arr[num]:
        if not check[next]:
            DFS(next, depth + 1)
    check[num] = False

for i in range(n):
    DFS(i, 0)

print(0)