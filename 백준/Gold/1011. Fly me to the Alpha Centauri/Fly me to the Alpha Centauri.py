

t = int(input())

ans = []
for i in range(t):
    x, y = map(int, input().split())

    d = y - x

    # 초기 값을 설정한다.
    move = 0
    # 이동 횟수를 세준다.
    dist = 0
    # 누적 이동 거리를 계산
    step = 1
    # 현재 이동 가능한 최대 거리

    while dist < d:
        move += 1
        dist += step

        # 짝수번 이동 후에 step을 증가시킨다.
        # 이 규칙을 통하여 거리를 대칭적으로 늘리며 목표 거리에 다가간다.
        # 이동 패턴이 1, 1, 2, 2, 3, 3, ,,, 과 같이 되면 이동 거리를 효율적으로 줄일 수 있다.
        # 1, 2, 3, 3, 2, 1 과 같은 형태로 되어야 하므로 이렇게 % 2를 통해 찾으면 좋다.
        if move % 2 == 0:
            step += 1

    ans.append(move)

for k in ans:
    print(k)

# 이전에 k광년을 이동하였을 경우 k-1, k, k+1 광년만을 이동할 수 있다.
# y지점에 도착하기 바로 직전의 이동거리는 반드시 1광년이어야 한다.


