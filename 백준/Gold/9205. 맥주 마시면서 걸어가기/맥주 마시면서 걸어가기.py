
from collections import deque

def dist(a, b):
    return abs(a[0] - b[0]) + abs(a[1] - b[1])

t = int(input())
for _ in range(t):
    n = int(input())

    arr = []
    home = list(map(int, input().split()))
    arr.append(home)
    for _ in range(n):
        store = list(map(int, input().split()))
        arr.append(store)
    fest = list(map(int, input().split()))
    arr.append(fest)

    q = deque([home])
    check = set()
    check.add(str(home))

    flag = False
    while q:
        now = q.popleft()
        if now == fest:
            flag = True
            break

        for next in arr:
            if str(next) not in check:
                distance = dist(now, next)
                if distance <= 1000:
                    check.add(str(next))
                    q.append(next)

    # 계속 q로 갈 수 있는 길들을 이어나가다가 now가 끝에 도착하면 flag가 true

    print("happy" if flag else "sad")



# 맥주 한 박스에 맥주 20개
# 50미터에 한 병씩