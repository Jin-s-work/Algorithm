

n, d, k, c = map(int, input().split())
# 접시 개수, 초밥 가짓수, 연속해서 먹는 접시 수, 쿠폰 번호

sushi = []
for i in range(n):
    a = int(input())
    sushi.append(a)

# 임의의 위치부터 k개의 접시를 연속해서 먹으면 할인
# 쿠폰을 발행하고 쿠폰에 있는 초밥 무료 제공
# 최대한 다양하

check = [0] * (d + 1)
sushi = sushi + sushi
arr = []
ans = 0
cnt = 0

# 처음 k개에 대해서 세팅
for i in range(k):
    if check[sushi[i]] == 0:
        cnt += 1
    check[sushi[i]] += 1

for i in range(n):
    # 뒤로 늘리기
    if check[sushi[i + k]] == 0:
        cnt += 1
    check[sushi[i + k]] += 1

    # 앞에 지우기
    if check[sushi[i]] - 1 == 0:
        cnt -= 1
    check[sushi[i]] -= 1

    if check[c] == 0:
        ans = max(ans, cnt + 1)
    else:
        ans = max(ans, cnt)

print(ans)
