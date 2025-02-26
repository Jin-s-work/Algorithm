

# 계란을 계란으로 치면 내구도는 상대 계란의 무게만큼 깎인다.
# 내구도가 0 이하가 되면 깨진다.

# 가장 왼쪽의 계란을 든다.
# 든 계란으로 깨지지 않은 계란 중 하나를 친다. 깨졌거나 다른 계란이 없다면 넘어간다.
# 최근에 든 계란의 오른쪽 계란을 들고 2번을 다시 진행
# 끝에 오면 종료

n = int(input())
arr = []
for _ in range(n):
    s, w = map(int, input().split())
    arr.append([s, w])
    # 내구도, 무게

ans = 0
def DFS(num, cnt):
    global ans
    if num == n:
        ans = max(ans, cnt)
        return

    if arr[num][0] <= 0:
        DFS(num + 1, cnt)
        return

    check = False
    for i in range(n):

        if i == num or arr[i][0] <= 0:
            continue
        # 원래는 여기에 arr[num][0] <= 0 을 넣으려고 했는데
        # 그러면 num의 계란이 깨졌다고 continue 하면 다른 계란들로 넘어가지 못한다.

        arr[num][0] -= arr[i][1]
        arr[i][0] -= arr[num][1]
        check = True

        broke = 0
        if arr[num][0] <= 0:
            broke += 1
        if arr[i][0] <= 0:
            broke += 1

        DFS(num + 1, cnt + broke)
        arr[num][0] += arr[i][1]
        arr[i][0] += arr[num][1]

    # 안치고 다음으로 넘어갈 수도 있으므로 이렇게 진행한다.
    if not check:
        DFS(num + 1, cnt)

DFS(0, 0)
print(ans)