

# i번 강의와 j번 강의를 같은 곳에 녹화하려면 모든 강의도 같은 블루레이에 녹화해야한다.

n, m = map(int, input().split())
arr = list(map(int, input().split()))

# m개로 나누어서 크기 중 최소를 구해야 한다.

def movie(size):
    s = 0
    cnt = 1
    for i in range(n):
        if s + arr[i] > size:
            cnt += 1
            s = 0
        s += arr[i]
    return cnt
# size에 따라서 몇개까지로 나눌 수 있는지 찾는다.

left = max(arr) # 최소 블루레이 크기
right = sum(arr)  # 최대 블루레이 크기
ans = right
while left <= right:
    mid = (left + right) // 2
    if movie(mid) <= m:
        ans = min(ans, mid)
        right = mid - 1
    else:
        left = mid + 1
# 값보다 작을 때 더 작은 값일 때도 되는지 확인해야 하므로
# m이하일 때, right = mid - 1로 해준다.

print(ans)


# 나눌 때 개수를 세서 여기에서 m을 안넘으면 그것이 최소
