

n = int(input())

arr = list(map(int, input().split()))

ans = 0
def DFS(energy, beads):
    global ans
    if len(beads) == 2:
        ans = max(ans, energy)
        return

    for i in range(1, len(beads)-1):
        gain = beads[i-1] * beads[i+1]

        # i번째를 없애준다.
        remove = beads.pop(i)
        DFS(energy + gain, beads)
        beads.insert(i, remove)
        # 다시 뺀 값을 넣어준다.

DFS(0, arr)
# 배열 자체를 계속 바꾸어주며 넣어주면서 백트래킹을 이용하면 된다.

print(ans)