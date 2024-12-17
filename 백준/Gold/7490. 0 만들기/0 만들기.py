

def DFS(num, idx, last, st):

    if idx == n:
        if num + last == 0:
            ans.append(st)
        return

    next = idx + 1
    DFS(num + last, idx + 1, next, st + "+" + str(next))
    DFS(num + last, idx + 1, -next, st + "-" + str(next))

    # 숫자를 이어붙이는 경우
    if last > 0:
        new_last = last * 10 + next
    else:
        new_last = last * 10 - next

    DFS(num, idx + 1, new_last, st + " " + str(next))


t = int(input())
for _ in range(t):
    n = int(input())

    ans = []

    DFS(0, 1, 1, "1")
    # 처음 합, 인덱스, 다음 숫자, 1부터 하므로

    ans = sorted(ans)
    for k in ans:
       print(k)
    print()
