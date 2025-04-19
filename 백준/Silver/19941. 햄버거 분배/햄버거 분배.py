
# 식탁의 길이 n
# 사람들은 자신의 위치에서 거리가 k 이하인 햄버거를 먹을 수 있다.
n, k = map(int, input().split())
arr = list(input())

check = [0] * n
ans = 0

for i in range(n):
    if arr[i] == 'P':
        # 0과 범위 중에 제일 큰 값 부터 n과 범위 최대 중 더 작은 값을 기준으로 검사한다.
        for j in range(max(0, i-k), min(n, i + k + 1)):
            if arr[j] == 'H' and not check[j]:
                check[j] = True
                ans += 1
                break
                # 사람을 찾으면 더 찾기 않고 끝내야한다.

print(ans)