import sys
input = sys.stdin.readline

import heapq

n = int(input())
   
arr = []
for _ in range(n):
    a, b = map(int, input().split())
    arr.append([a, b])

arr.sort()

rm = []
heapq.heappush(rm, arr[0][1])
# 일단 먼저 처음 arr의 끝나는 시간을 넣는다.

for i in range(1, n):
    if arr[i][0] < rm[0]:
        heapq.heappush(rm, arr[i][1])
    # 끝나는 시간 보다 안에 있을 경우 새로 회의실 개설한다.
    else: # 새로운 회의 개최 가능
        heapq.heappop(rm)
        # 새로운 회의로 시간 변경을 위해 pop 해준 뒤에 새 시간을 push한다.
        heapq.heappush(rm, arr[i][1])

print(len(rm))

            
