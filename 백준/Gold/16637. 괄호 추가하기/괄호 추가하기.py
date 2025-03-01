

n = int(input())
exp = input()

import sys
ans = -sys.maxsize

def Cal(a, op, b):
    if op == '+':
        return a + b
    elif op == '-':
        return a - b
    elif op == '*':
        return a * b

def DFS(idx, num):
    global ans

    if idx >= n-1:
        ans = max(ans, num)
        return
    # 모든 연산을 수행하면 최댓값 갱신

    # 괄호없이 바로 계산하는 경우
    next = Cal(num, exp[idx], int(exp[idx + 1]))
    # 숫자에다가 현재 연산자와 그 다음 숫자로 계산한다.
    DFS(idx + 2, next)
    # 계산 후에 idx + 2로 이동해서 다음 연산을 수행한다.

    # 괄호를 추가해서 먼저 계산하는 경우 먼저 연산을 수행한 후에 기존 값과 연산한다.
    if idx + 2 < n:
        tmp = Cal(int(exp[idx + 1]), exp[idx + 2], int(exp[idx + 3]))
        # 괄호 계산 괄호가 있다고 치고 먼저 계산하는 것이다.
        next = Cal(num, exp[idx], tmp)
        # 그 결과를 기존 값과 다시 연산하는 것이다.
        # 뒤의 괄호를 계산하고 -> 기존 값과 원래의 연산
        DFS(idx + 4, next)

DFS(1, int(exp[0]))
print(ans)