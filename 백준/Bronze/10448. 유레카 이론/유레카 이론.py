

t = int(input())

eu = []
for i in range(1, 46):
    num = (i * (i + 1)) // 2
    eu.append(num)

def check(n):
    for i in eu:
        for j in eu:
            for k in eu:
                if n == (i + j + k):
                    return 1
    return 0

for _ in range(t):
    n = int(input())
    print(check(n))



