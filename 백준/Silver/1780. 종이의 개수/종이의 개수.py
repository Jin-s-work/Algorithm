

n = int(input())
arr = []
counts = {-1:0, 0:0, 1:0}
# dict를 사용해서 푼다.

for i in range(n):
    tmp = list(map(int, input().split()))
    arr.append(tmp)

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
        counts[first] += 1
        # first의 값에 대해서 한개 추가해준다.
    # 아닌경우에는 9개로 나뉘어서 들어간다.
    else:
        m = num//3
        # 3*3으로 나누어서 재귀한다.
        for nx in (0, m, 2*m):
            for ny in (0, m, 2*m):
                func(a + nx, b + ny, m)

func(0, 0, n)
print(counts[-1])
print(counts[0])
print(counts[1])
