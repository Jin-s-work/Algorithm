
n = int(input())

arr = []
for i in range(n):
    tmp = input()
    arr.append(tmp)

# 4개로 분할
def func(a, b, num):
    first = arr[a][b]
    check = True

    for i in range(a, a + num):
        for j in range(b, b + num):
            if arr[i][j] != first:
                check = False
                break
        if not check:
            break

    if check:
        return first
    else:
        m = num // 2
        one = func(a, b, m)
        two = func(a, b + m, m)
        three = func(a + m, b, m)
        four = func(a + m, b + m, m)
        return "(" + one + two + three + four + ")"

print(func(0, 0, n))
