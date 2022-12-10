n = int(input())
a = []
b = []
a = list(map(int, input().split()))
b = list(map(int, input().split()))
# arr에 넣어주는 것이 아닌 하나의 경우일때는 이런식
a.sort()
b.sort(reverse=True)
ans = 0
for i in range(n):
    ans += (a[i] * b[i])
print(ans)

# 1 2 3 4 5
# 5 4 3 2 1
# 5 8 9 8 5  = 35
# 1 4 9 16 25 = 더 큼
