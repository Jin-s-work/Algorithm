

v, e = map(int, input().split())

def find(parent, x):
    if parent[x] != x:
        parent[x] = find(parent, parent[x])
    return parent[x]

def union(parent, rank, a, b):
    aa = find(parent, a)
    bb = find(parent, b)

    if aa != bb:
        if rank[aa] > rank[bb]:
            parent[bb] = aa
        elif rank[aa] < rank[bb]:
            parent[aa] = bb
        else:
            parent[bb] = aa
            rank[aa] += 1



arr = []
for _ in range(e):
    a, b, c = map(int, input().split())
    arr.append((c, a, b))

arr.sort()
# 가중치 기준으로 정렳한다.
parent = [i for i in range(v + 1)]
rank = [0] * (v + 1)

mst_sum = 0
edge_cnt = 0

for cost, a, b in arr:
    if find(parent, a) != find(parent, b):  # 사이클이 발생하지 않으면
        union(parent, rank, a, b)
        mst_sum += cost
        edge_cnt += 1
        if edge_cnt == v - 1:
            break

print(mst_sum)