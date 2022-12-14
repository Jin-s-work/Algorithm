from itertools import permutations

n = int(input())
k = int(input())
arr = []
for _ in range(n):
    arr.append(str(input()))

if k == 2:
    two = list(map(''.join, permutations(arr, 2)))
    two = list(set(two))
    print(len(two))
elif k == 3:
    three = list(map(''.join, permutations(arr, 3)))
    three = list(set(three))
    print(len(three))
elif k == 4:
    four = list(map(''.join, permutations(arr, 4)))
    four = list(set(four))
    print(len(four))
