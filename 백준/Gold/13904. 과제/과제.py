
n = int(input())
arr = []
for _ in range(n):
    d, w = map(int, input().split())
    arr.append((d, w))

# 모든 과제를 끝내지 못할 수도 있다. 마감일이 지난 과제는 점수를 받을 수 없다.
# 가장 점수를 많이 받을 수 있게 수행
# 과제는 하루에 하나

# 40 50 30 60 5
# 기한이 짧아도 더 점수가 높은 걸 먼저 하는게 맞다

arr.sort(key=lambda x : -x[1])
# 전략 : 점수가 높은 과제부터 선택한다.
#       가능한 가장 늦은 날짜에 배정한다.
#       그 날이 비어있으면, 수행하고 다른 과제가 있으면 스킵한다.

day = [0] * 1001
for day_left, score in arr:
    num = day_left
    while day[num] != 0:
        num -= 1
    if num > 0:
        day[num] = score

print(sum(day))

