

n, k, d = map(int, input().split())
arr = []
for _ in range(k):
    a, b, c = map(int, input().split())
    arr.append((a, b, c))

# 도토리 d개
# n개의 상자에 도토리를 넣어 전부 숨기려고 한다.
# a번 상자부터 b번 상자까지 c개 간격으로 도토리를 하나씩 더 넣는 규칙

# 1부터 n번 상자까지 중, x번 상자까지 도토리를 넣었을때, d개 이상이 처음 되는 x
# x번 상자까지 도토리를 넣었는데 d개 이상 넣을 수 있다면,
# x보다 왼쪽에 정답이 있을 수 있으므로 left를 줄여야 한다.

# 그 박스번호에 대해서 그 박스에 있는지 확인하는 것이다.
def rule(num):
    total = 0
    for a, b, c in arr:
        if num < a:
            continue
        # 범위 밖이므로 도토리 없다.
        last = min(b, num)
        total += (last - a) // c + 1
    return total
    # x번 상자까지 몇개나 도토리를 넣을 수 있는지
# ***********
# 이 함수에서 1번 상자부터 num번째 상자까지 도토리를 몇개 넣을 수 있는지 알려준다.
# 그러면, 비교를 해나가면서 정확히 x번째 상자에 도토리가 d개를 넘을 때가 정답인 것!!!
# ***********


left = 1
right = 1000000000
ans = right
while left <= right:
    mid = (left + right) // 2
    if rule(mid) < d:
        left = mid + 1
    elif rule(mid) >= d:
        ans = min(ans, mid)
        right = mid - 1
# 도토리 d개를 넣을 수 있는 가장 작은 상자 번호를 찾는 것

print(ans)