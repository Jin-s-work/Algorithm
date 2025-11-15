
import sys
n = int(input())

def cal(a, op, b):
    if op == '+':
        return a + b
    if op == '-':
        return a - b
    return a * b

exp = input()

num = []
op = []
for idx, ch in enumerate(exp):
    if idx % 2 == 0:
        num.append(int(ch))
    else:
        op.append(ch)
# 숫자와 연산자 따로 넣어준다.

if not op:
    print(num[0])
    sys.exit(0)

ans = -sys.maxsize

def DFS(i, acc):
    global ans
    if i == len(op):
        ans = max(ans, acc)
        return

    # 괄호 없이 현재 연산을 적용
    v1 = cal(acc, op[i], num[i + 1])
    DFS(i + 1, v1)

    # 다음 한 연산을 괄호로 먼저 계산 한 후에 현재 연산에 붙이기
    if i + 1 < len(op):
        mid = cal(num[i + 1], op[i + 1], num[i + 2])
        v2 = cal(acc, op[i], mid)
        DFS(i + 2, v2)
    # 다음 값이 괄호를 사용한다 가정하고 들어가

DFS(0, num[0])
print(ans)