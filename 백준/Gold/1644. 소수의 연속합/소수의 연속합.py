
import math
n = int(input())

Max = 4000000
check = [0] * (Max + 1)
for i in range(2, int(Max ** 0.5) + 1):
    # i가 True가 아니라면
    if not check[i]:
        # i가 소수일 경우
        for j in range(i * i, Max + 1, i): # i*i부터 i의 배수를 전부 제거한다. (소수)
            check[j] = True
# 내가 원래 하려고 했던 부분은 i를 전체로 하는 것이었지만,
# 아직 check가 되지 않은 부분에 대해서 그 수의 배수들을 True로 한다.

prime = []
for i in range(2, Max + 1):
    if not check[i]:
        prime.append(i)
# 소수들을 이 행렬에 넣는다.

ans = 0
left, right = 0, 0
s = prime[0]
a = []
while right < len(prime):
    if s >= n:
        if s == n:
            ans += 1
            a.append(right)
        s -= prime[left]
        left += 1

    else:
        right += 1
        if right < len(prime):
            s += prime[right]

print(ans)


