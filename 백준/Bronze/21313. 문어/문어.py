n = int(input())

arr = []
if n % 2 == 0:
    for k in range(n//2):
        arr.append(1)
        arr.append(2)
else:
    for k in range(n//2):
        arr.append(1)
        arr.append(2)
    arr.append(3)

for k in arr:
    print(k, end=" ")