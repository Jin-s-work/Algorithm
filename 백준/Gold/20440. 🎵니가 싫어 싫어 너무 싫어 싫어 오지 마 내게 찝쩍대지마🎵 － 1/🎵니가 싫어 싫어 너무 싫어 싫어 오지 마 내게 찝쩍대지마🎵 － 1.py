
from collections import defaultdict
n = int(input())

dic = defaultdict(int)
for _ in range(n):
    a, b = map(int, input().split())
    dic[a] += 1
    dic[b] -= 1

# 모기가 가장 많이 있는 시간대와 해당 시간에 몇마리 있는지 구하기
# 시간대를 출력한다.

# 모기의 수와 시간이 어마어마하게 크다 흐음
# 좌표 압축으로 풀어야 한다.
# hashmap key value를 통해서 특정 key에 접근할 시 지정한 타입으로 Value를 초기화

start, end = 0, 0
ans, num = 0, 0
check = False

for i in sorted(dic.keys()):
    num += dic[i]
    # 이렇게 하면 각 시간마다 모기 수를 알 수 있다.

    # 늘려나가다가 커지면 갱신
    if num > ans:
        ans = num
        start = i
        check = True
    # 커진 값이 맞고, num - dic[i]가 아직 ans 일 경우
    # end를 바꿔주고, check도 원래대로 돌린다.
    elif num < ans and num - dic[i] == ans and check:
        end = i
        check = False

print(ans)
print(start, end)



