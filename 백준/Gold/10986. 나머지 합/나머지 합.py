

n, m = map(int, input().split())
arr = list(map(int, input().split()))

mod_cnt = [0] * m
mod_cnt[0] = 1

prefix = 0
ans = 0
for k in arr:
    prefix += k
    remain = prefix % m
    # 올라가면서 prefix에 대해서 나머지해줌
    ans += mod_cnt[remain]
    # 나머지에 따라서 개수들을 누적시켜서 계속 더해준다.
    # 1 + 2 +... + n 의 경우

    mod_cnt[remain] += 1
    # 개수가 늘었으니 하나 늘려준다

print(ans)




# 중요 포인트 : s[j] % m == s[i] % m 이면, i부터 j까지는 m으로 나누어 떨어진다.