

st = input()

# 쇠막대기는 자신보다 긴 쇠막대기 위에만 놓인다. 끝점은 겹치면 안된다.
# 각 쇠막대기를 자르는 레이저는 적어도 하나 존재한다.
# 레이저는 어떠한 쇠막대기의 양 끝점과도 겹치지 않는다.

from collections import deque

q = deque()
num = 0
before = ""
ans = 0
for k in st:
    if k == '(':
        q.append('(')
    else:
        q.pop()
        # 막대기 개수는 )가 나올때마다 줄어든다.
        if before == '(':  # 레이저인 경우 괄호 만큼 추
            ans += len(q)
        else:
            ans += 1
            # 그냥 막대기의 끝일 경우 조각 하나를 추가해준다.
            # 막대기의 끝에는 마지막 조각이 생기기 때문에 한개를 더 추가해주어야 한다.
            # 마지막일때!!

    before = k


print(ans)