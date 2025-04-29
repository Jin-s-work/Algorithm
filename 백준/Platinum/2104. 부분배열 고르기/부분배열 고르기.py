import sys
input = sys.stdin.readline

n = int(input())
arr = list(map(int, input().split()))

# 누적합 배열 (구간 합 계산용)
prefix = [0] * (n + 1)
for i in range(n):
    prefix[i + 1] = prefix[i] + arr[i]

stack = []
answer = 0

for i in range(n):
    start = i
    while stack and stack[-1][0] >= arr[i]:
        height, start = stack.pop()
        total = prefix[i] - prefix[start]
        answer = max(answer, total * height)
    stack.append((arr[i], start))

# 스택에 남은 것 처리
while stack:
    height, start = stack.pop()
    total = prefix[n] - prefix[start]
    answer = max(answer, total * height)

print(answer)
