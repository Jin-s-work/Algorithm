

while True:
    n, m = input().split()
    n = int(n)
    m = int(float(m) * 100 + 0.5)
    if n == 0 and m == 0:
        break

    arr = []
    for i in range(n):
        c, p = input().split()
        c = int(c)
        p = int(float(p) * 100 + 0.5)
        arr.append((c, p))

    dp = [0] * 10001
    for i in range(n):
        for j in range(1, m+1):
            if j - arr[i][1] >= 0:
                dp[j] = max(dp[j], dp[j - arr[i][1]] + arr[i][0])

    print(max(dp))