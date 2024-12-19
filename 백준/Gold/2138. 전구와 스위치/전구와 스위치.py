

# i번 스위치를 누르면 i-1, i, i+1 전구의 상태가 바뀐다.
# n개의 전구들의 현재 상태와 우리가 만들고자 하는 상태가 주어짐

n = int(input())
current = list(map(int, input().strip()))
target = list(map(int, input().strip()))
# strip 은 문자열의 양쪽 공백을 제거한다.
# 공백이나 개행 문자를 제거해준다.

def toggle(state, idx, n):
    state[idx] ^= 1
    # 현재 위치를 토글
    if idx > 0:
        state[idx - 1] ^= 1
    if idx < n - 1:
        state[idx + 1] ^= 1
    # 0이랑 n-1 사이에 있을 경우 그 앞이나 뒤를 토글

def find(flag):
    state = current[:]
    cnt = 0

    if flag:
        toggle(state, 0, n)
        cnt += 1
    # 처음에 토글을 할 경우에는 토글을 시작하고 넘어간다.
    # 안하는 경우에는 그냥 넘어가기
    
    # 1부터 n까지 찾으면서 만약 전에 전구가 목표와 다를 경우에는
    # toggle을 통해서 바꾸어준다.
    for i in range(1, n):
        if state[i-1] != target[i-1]:
            toggle(state, i, n)
            cnt += 1

    # 같을 경우에 횟수를 리턴하고 아니면 inf 리턴
    if state == target:
        return cnt
    else:
        return float('inf')

# 따라서 첫번째를 할 경우와 안할 경우를 나누어서 그 중에 더 작은 값을 넣는다.
ans = min(find(True), find(False))
if ans == float('inf'):
    print(-1)
else:
    print(ans)