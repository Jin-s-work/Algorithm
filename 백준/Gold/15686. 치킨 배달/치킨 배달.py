
from itertools import combinations

n, m = map(int, input().split())

arr = []
for i in range(n):
    tmp = list(map(int, input().split()))
    arr.append(tmp)

house = []
chicken = []
for i in range(n):
    for j in range(n):
        if arr[i][j] == 2:
            chicken.append([i, j])
        elif arr[i][j] == 1:
            house.append([i, j])

def get_dist(select):
    total = 0
    for nx, ny in house:
        Min = float('inf')

        for cx, cy in select:
            distance = abs(nx - cx) + abs(ny - cy)
            Min = min(Min, distance)

        total += Min

    return total


# 조합을 이용하여 모든 경우의 수를 세준다.
ans = float('inf')
for chick in combinations(chicken, m):
    dist = get_dist(chick)
    ans = min(ans, dist)

print(ans)