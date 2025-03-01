
from itertools import combinations
import copy

n, m, d = map(int, input().split())

arr = []
for _ in range(n):
    tmp = list(map(int, input().split()))
    arr.append(tmp)

# 궁수는 3명을 배치하려고 하고
# 궁수의 공격으로 제거할 수 있는 적의 최대 수
# 턴마다 적 하나를 공격할 수 있고, 적이 여럿일 겨웅에는 가장 왼쪽에 있는 적을 공격
# 공격이 끝나면, 적이 아래로 한칸 이동한다.
# 공격 거리 제한은 d

# 전체를 내려가게 하면 번거로우니까 궁수를 올리는 방향으로?

archer_pos = list(combinations(range(m), 3))

def attack(archers, grid):
    target = set()
    for archer_y in archers:
        enemy = None
        Min = d + 1

        for x in range(n):
            for y in range(m):
                if grid[x][y] == 1:
                    # 궁수 위치와의 거리 계산
                    dist = abs(n - x) + abs(archer_y - y)
                    if dist <= d:
                        # 거리가 이하이거나 같은데 y값은 더 작을 경우에 갱신
                        if dist < Min or (dist == Min and y < enemy[1]):
                            enemy = (x, y)
                            Min = dist

        if enemy:
            target.add(enemy)
        # 해당 턴에 공격할 대상 정한다.

    return target

def simulate(archers):
    grid = copy.deepcopy(arr)
    kill = 0

    # 적이 남아있는 동안 반복한다.
    while any(1 in row for row in grid):
        target = attack(archers, grid)
        # 공격할 적을 target에 넣는다.

        for x, y in target:
            grid[x][y] = 0
            kill += 1

        grid.pop()
        # 맨 아래의 적을 제거한다.
        grid.insert(0, [0] * m)
        # 맨 위에 빈 행을 추가해준다.

    return kill

ans = 0
for archers in archer_pos:
    ans = max(ans, simulate(archers))

print(ans)
