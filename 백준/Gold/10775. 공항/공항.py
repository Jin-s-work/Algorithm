

g = int(input())
p = int(input())

def find(parent, x):
    if parent[x] != x:
        parent[x] = find(parent, parent[x])
    return parent[x]

def union(parent, a, b):
    parent[find(parent, a)] = find(parent, b)

parent = [i for i in range(g + 1)]
# 각 게이트는 그 자신이 루트이다.
ans = 0
for _ in range(p):
    gi = int(input())
    root = find(parent, gi)

    if root == 0:
        break
    # 0일 경우 안되므로 break

    # 도킹한 후, 현 게이트는 사용되었으니 바로 왼쪽 게이트로 병합한다.
    union(parent, root, root - 1)
    ans += 1

print(ans)

# find(x)는 x번 게이트보다 작거나 같은 가장 오른쪽 빈 게이트를 찾는다.
# union(x, x-1)은 x번 게이트에 도킹 후, 해당 게이트를 x-1번 게이트와 연결하여 다음번에 건너뛰도록한다.