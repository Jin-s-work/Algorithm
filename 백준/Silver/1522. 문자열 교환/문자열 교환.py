

a = input()
n = len(a)

a_cnt = a.count('a')
st = a + a

# 처음에 총 a의 개수를 세주고 그 안에 b가 몇개 있는지만 세면 된다.
b_cnt = st[:a_cnt].count('b')
Min_cnt = b_cnt
# 그 안에 있는 b의 개수를 세준다.

# 슬라이딩 윈도우를 이용하여 이렇게 옮겨다니면서 a_cnt의 길이에 알맞는 b를 세준다.
for i in range(1, n):
    if st[i-1] == 'b':
        b_cnt -= 1
    # 문자열의 길이가 a_cnt이므로 그 뒤의 문자열의 인덱스는 i + a_cnt - 1이다.
    if st[i + a_cnt - 1] == 'b':
        b_cnt += 1
    # 왼쪽이 b면 b를 줄여주고, 오른쪽이 b면 늘려준다.
    # 왼쪽 끝이 b일 경우에는 옮기는 과정에서 b가 빠져나가므로 1 줄여준다.
    # 오른쪽 끝이 b가 추가되면 b는 1 늘려준다.

    Min_cnt = min(Min_cnt, b_cnt)

print(Min_cnt)