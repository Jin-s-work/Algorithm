from collections import Counter

n = int(input())
arr = list(map(int, input().split()))
m = int(input())
arr2 = list(map(int, input().split()))
ans = []
count = Counter(arr)
# Counter는 리스트를 값으로 주면 해당 원소들이 몇번 등장했는지
# 찾아서 딕셔너리 형태로 반환한다.
# 여기서는 arr에 대해서 각 원소들의 수를 세줌

for i in range(len(arr2)):
    if arr2[i] in count:   # arr2[i]가 count에 있을 경우
        print(count[arr2[i]], end = ' ')
    else:       # count의 arr2[i]에 넣는다.
        print(0, end = ' ')
