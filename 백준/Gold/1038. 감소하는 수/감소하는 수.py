

n = int(input())
arr = []

def DFS(num, last_digit):
    arr.append(num)

    # 이런 식으로 제일 마지막 수보다 작은 것을 넣어서 추가해준 다음에
    # DFS로 들어가준다.
    for i in range(last_digit):
        next = num * 10 + i
        DFS(next, i)

for i in range(10):
    DFS(i, i)

arr.sort()

if n < len(arr):
    print(arr[n])
else:
    print(-1)
