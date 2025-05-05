
# 최대 생명력 : 1이상이어야 한다. 이후로 변하지 않는다.
# 현재 생명력 : 들어가기전에는 최대 생명력과 같다. 최대보다 더 커질 수 없다.
# 공격력

# 던전은 총 n개의 방, i번째 방에서만 i+1번째 방으로 이동 가능

n, atk = map(int, input().split())

arr = []
for _ in range(n):
    t, a, h = map(int, input().split())
    arr.append((t, a, h))

# t가 1이면 공격력이 a, 생명력이 h
# t가 2이면 공격력을 a증가, 생명력 h회복 포션 존재
# n번방의 용을 쓰러트리기 위한 최대 체력을 계산
# 따라서 최대 체력에 따라서 계산하는 함수를 만들고
# 최대 체력도 이분 탐색으로 확인하는 함수를 만든다.

def clear(hp):
    max_hp = hp
    now_hp = hp
    at = atk

    for i in range(n):
        tt, aa, hh = arr[i]
        if tt == 1:
            # 몬스터가 죽는 데 필요한 턴수 : ceil(h / at)
            # 용사는 반격을 turns-1번 당한다.
            # 받는 데미지 : (turns - 1) * 공격력
            turns = (hh + at - 1) // at
            damage = (turns - 1) * aa
            now_hp -= damage
            if now_hp <= 0:
                return False
            # 모든 턴을 다 돌면서 탐색하면 오래걸리니까
            # 미리 계산을 해서 한번에 다 되게 한다.
            # 이걸로 하니까 진자 빨리 계산이 된다 싱기..

        if tt == 2:
            at += aa
            now_hp = min(now_hp + hh, max_hp)

    return True

left = 1
right = 1 << 63
ans = 1 << 63

while left <= right:
    mid = (left + right) // 2
    if clear(mid):
        right = mid - 1
        ans = min(ans, mid)
    else:
        left = mid + 1

print(ans)
