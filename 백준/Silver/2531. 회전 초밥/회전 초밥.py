

# 임의의 위치부터 k개의 접시를 연속적으로 먹고 할인된 정액 가격
# 초밥의 종류 하나가 쓰인 쿠폰을 발행하고, 1번 행사에 참가하면 이 쿠폰에 적힌 초밥 하나 추가 무료 제공
# 이 번호에 적힌 초밥이 없을 경우 새로 만들어 제공한다.



n, d, k, c = map(int, input().split())
# 접시수, 초밥수, 연속 접시수, 쿠폰 번호

arr = []
for i in range(n):
    a = int(input())
    arr.append(a)

sushi = [0] * (d + 1)
cnt = 0

for i in range(k):
    # 고유한 초밥 종류의 개수를 cnt에 추가해준다.
    if sushi[arr[i]] == 0:
        cnt += 1
    sushi[arr[i]] += 1
    # sushi에서 셀 수 있게 더해준다.

ans = cnt + (1 if sushi[c] == 0 else 0)
# 처음에는 처음에 시작한 부분을 계산해준다.

for i in range(1, n):
    # 왼쪽 초밥을 제거한다.
    left = arr[i-1]
    # left를 지워주는 과정
    sushi[left] -= 1
    if sushi[left] == 0:
        cnt -= 1

    # 오른쪽 초밥을 제거한다.정
    # 범위를 넘으면 i + k - 1 해준 다음에 나머지로 원형 큐 계산
    right = arr[(i + k - 1) % n]
    # right를 더해주는 과
    if sushi[right] == 0:
        cnt += 1
    sushi[right] += 1

    ans = max(ans, cnt + (1 if sushi[c] == 0 else 0))

print(ans)