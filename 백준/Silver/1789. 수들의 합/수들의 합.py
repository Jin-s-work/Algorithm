

s = int(input())

n = 1
while True:
    num = n * (n + 1) // 2
    if num > s:
        break
    n += 1

print(n - 1)


