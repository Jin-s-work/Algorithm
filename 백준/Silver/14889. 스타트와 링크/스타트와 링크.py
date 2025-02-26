

# Sij는 i번과 j번이 같은 팀에 속했을때, 더해지는 능력치이다.
# Sij와 Sji는 다를 수도 있다.

# 두 팀의 능력치 차이를 최소로 하려고 한다.


import sys
from itertools import combinations

n = int(input())
arr = []
for i in range(n):
    tmp = list(map(int, input().split()))
    arr.append(tmp)

Min = sys.maxsize
check = [0] * (n + 1)

def cal_diff():
    start = 0
    link = 0

    for i in range(n):
        for j in range(n):
            if check[i] and check[j]:
                start += arr[i][j]
            elif not check[i] and not check[j]:
                link += arr[i][j]

    global Min
    Min = min(Min, abs(start - link))


def DFS(idx, cnt):
    if cnt == n // 2:
        cal_diff()
        return

    # 중복을 방지하기 위해 idx부터 탐색
    for i in range(idx, n):
        if not check[i]:
            check[i] = True
            DFS(i + 1, cnt + 1)
            # idx도 올라가주고, 횟수가 n//2만큼이어야 한다.
            check[i] = False

DFS(0, 0)
print(Min)