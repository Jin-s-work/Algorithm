
from collections import defaultdict
n, k = map(int, input().split())
arr = list(map(int, input().split()))

dict = defaultdict(int)
dict[0] = 1
# s[0] = 0인데 한번 본걸로 시작한다.

s = 0
ans = 0
for num in arr:
    s += num
    ans += dict[s - k]
    # 전에 dict[s - k]가 과거에 몇번 나왔는지만 더해주면 된다.
    # 이렇게 dict를 이어가는 것
    dict[s] += 1

# 어떻게 보면 냅색 같은거네..
# s[i] - s[j] = k 는 s[j] = s[i] - k 이기에

print(ans)


# n이 20만이니까 O(n)으로 쭉 투 포인터로 풀면 안되려
# 이게 음수가 없으면 그렇게 해도 될거 같은데 음수때문에 변수

# 음 누적합을 넣어준 다음에 map으로 찾는듯..?

