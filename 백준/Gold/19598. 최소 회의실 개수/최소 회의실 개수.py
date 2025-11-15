
import heapq
n = int(input())

arr = []
for _ in range(n):
    a, b = map(int, input().split())
    arr.append((a, b))
arr.sort()
# 시작 시간 오름차

# 항상 바로 heapq에 넣는 습관 줄이기,,

room = []
for start, end in arr:
    if room and room[0] <= start:
        heapq.heappop(room)
    # 가장 빨리 끝나는 방이 s 이전에 비는 경우, 그 방 재사용

    heapq.heappush(room, end)
    # 현재 회의를 어떤 방에 배정하고, 그 방의 새로운 종료 시각을 넣는다.

print(len(room))
