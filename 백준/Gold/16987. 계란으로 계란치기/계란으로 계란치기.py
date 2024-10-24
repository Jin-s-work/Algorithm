

n = int(input())

arr = []
for i in range(n):
    s, w = map(int, input().split())
    arr.append([s, w])

# 계란의 내구도가 0 이하가 되면 깨진다.
# 각 계란의 내구도는 상대 계란의 무게만큼 깎인다.

# 가장 왼쪽의 계란을 든다.
# 손에 들고 있는 계란으로 깨지지 않은 계란 중 하나를 친다.
# 손에 든 계란이 깨지거나 깨지지 않은 계란이 없으면 넘어간다.
# 이후 손에 든 계란을 원래 자리에 내려놓고 3번을 진행
# 가장 최근에 든 계란의 한 칸 오른쪽 계란을 손에 들고 2번을 진행
# 가장 최근에 든 계란이 가장 오른쪽에 있는 계란일 경우 계란 치는 과정을 종료한다.

ans = 0
def DFS(idx):
    global ans

    # idx가 끝에 와서 확인하면 개수세서 갱신하고 종료
    if idx == n:
        cnt = 0
        for k in arr:
            if k[0] <= 0:
                cnt += 1
        ans = max(ans, cnt)
        return

    # 현재 계란이 깨져있으면 다음 계란으로 넘어간다.
    if arr[idx][0] <= 0:
        DFS(idx + 1)
        return

    check = False
    for i in range(n):
        # 본인은 깨트릴 수 없고, 부딪치려는 계란의 경도가 0이어도 안된다.
        if i != idx and arr[i][0] > 0:
            arr[idx][0] -= arr[i][1]
            arr[i][0] -= arr[idx][1]
            check = True

            DFS(idx + 1)

            arr[idx][0] += arr[i][1]
            arr[i][0] += arr[idx][1]
    # 다음으로 넘어가는 과정
    # 안개지는 계란들에 있어서 넘어가는 경우에 대하여 가지를 쳐야하기에
    # 이러한 식으로 DFS를 진행해주고 다시 나올 경우에는 달걀의 강도를 복구시켜야 하므로
    # 위와 같은 과정으로 한다.

    # 치지 않을 경우도 넘어가야 하므로 위와 같이 해야 한다.
    if not check:
        DFS(idx + 1)


DFS(0)

print(ans)