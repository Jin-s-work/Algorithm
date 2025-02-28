

n = int(input())
m = int(input())

if m != 0:
    arr = list(map(str, input().split()))
else:
    arr = []
    
# 가까운 채널은 완전탐색을 통해 찾으면서 갱신해주면 된다!!!

def not_broke(num):
    for number in str(num):
        if number in arr:
            return False
    return True

ans = abs(n - 100)
if not_broke(n):
    ans = min(ans, len(str(n)))

for i in range(1000000):
    if not_broke(i):
        s = abs(n - i) + len(str(i))
        ans = min(ans, s)

# 일단 3가지로 나눌 수가 있다.
# 처음 100에서 +, -를 눌러서 가기
# 수에 고장난 게 없을 경우 바로 눌러서 간다.
# 수에 고장난 게 있을 수 있으므로 완전탐색을 통해 가장 가까운 수에서 번호를 누르는 수 더해준다.

print(ans)