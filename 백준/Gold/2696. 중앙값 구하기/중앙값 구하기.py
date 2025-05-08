
import heapq
import sys
input = sys.stdin.readline

t = int(input())

for _ in range(t):
    m = int(input())
    arr = []

    while len(arr) < m:
        arr += list(map(int, input().split()))

    # max에는 지금까지 들어온 값 중 작은 절반을 저장
    # min에는 지금까지 들어온 값 중 큰 절반을 저장
    # 항상 max의 루트가 중앙값이 된다.
    max_heap = []
    min_heap = []
    ans = []
    for i in range(m):
        num = arr[i]

        if len(max_heap) == len(min_heap):
            heapq.heappush(max_heap, -num)
        else:
            heapq.heappush(min_heap, num)
        # 둘의 크기가 같을 경우에는 최대힙에 넣고 다를 경우 최소힙

        # 항상 max_heap[0] <= min_heap[0]이 만족되어야 한다.
        # 중앙값을 제대로 구해주기 위해서
        if min_heap and -max_heap[0] > min_heap[0]:
            max_top = -heapq.heappop(max_heap)
            min_top = heapq.heappop(min_heap)

            heapq.heappush(max_heap, -min_top)
            heapq.heappush(min_heap, max_top)
        # 최소힙이 존재하고, 최대힙의 최대값인 [0]이 최소힙의 최솟값보다 클 경우에 바꿔준다.

        if i % 2 == 0:
            ans.append(-max_heap[0])
        # 홀수번째에 있을 때 중간값을 답에 넣어준다.

    print(len(ans))
    for i in range(0, len(ans), 10):
        print(*ans[i : i + 10])
    # 10개씩 출력해준다.


# 그냥 리스트로 중앙값을 찾으면 O(n^2logn)
