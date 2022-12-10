from itertools import combinations
arr = [int(input()) for _ in range(9)]

for i in combinations(arr, 7):
    if sum(i) == 100:   # 중복없이 뽑은 거의 합이 100일때
        for j in sorted(i):  # i를 정렬해서 프린트
            print(j)
        break
