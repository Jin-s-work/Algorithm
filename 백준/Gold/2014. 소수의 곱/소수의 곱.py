
import heapq
import sys
input = sys.stdin.readline

k, n = map(int, input().split())
arr = list(map(int, input().split()))

s = set()
pq = []

for i in range(k):
    heapq.heappush(pq, arr[i])
    s.add(arr[i])

cnt = 0
num = 0
while cnt < n:
    num = heapq.heappop(pq)
    cnt += 1
    # 우선 순위 큐에서는 항상 가장 작은 수를 먼저 pop한다.
    # cnt가 n이 될때까지 반복하므로
    # n번째로 pop한 값이 곧 정렬된 수열에서 n번째 수가 된다.

    for p in arr:
        new_prime = num * p

        if new_prime > 2 ** 31:
            break
        if new_prime not in s:
            heapq.heappush(pq, new_prime)
            s.add(new_prime)
        if num % p == 0:
            break
        # 이게 생각하기 어려운 포인트인데 이렇게 해서 중복되는 걸 줄인다.
        # num이 p로 이미 나누어지는 경우에 num이 p보다 작거나 같은 소수로 만들어진 수
        # 곱해봤자 같은 수를 다른 경로로 또 만들 가능성이 있다.

        # 이미 만들 수 있는 조합은 처음 한번만 만들고, 이후 조합은 건너뛴다.
        # 솔직히 코테에 나왓을때 완벽하게 생각할 수 있으려나....

print(num)
# n번하고 딱 나왔을때의 값이 n번째 나오는 것이다.