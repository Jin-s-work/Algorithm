

n, score, p = map(int, input().split())
if n == 0:
    print(1)
    exit()

arr = list(map(int, input().split()))

if n == p and arr[-1] >= score:
    print(-1)
else:
    rank = 1
    for i in range(n):
        if arr[i] > score:
            rank += 1
        else:
            break
    print(rank)