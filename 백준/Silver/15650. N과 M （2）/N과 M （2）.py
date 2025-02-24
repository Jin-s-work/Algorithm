

n, m = map(int, input().split())

arr = [0] * (n + 1)

# 현재 선택한 개수, 선택할 숫자의 시작점
def DFS(num, cnt):
    if num == m:
        for i in range(m):
            print(arr[i], end = " ")
        print()
        return

    # cnt보다 큰 숫자부터 해야하므로 매개변수가 2
    # 이전보다 큰 숫자만 선택 (cnt부터 n까지 탐색)
    for i in range(cnt, n + 1):
        arr[num] = i
        DFS(num + 1, i + 1)
        # 현재 위치에 숫자를 저장하고, 다음 숫자를 선택한다.

DFS(0, 1)
# 0개 선택된 상태에서, 숫자 1부터 선택 시작한다.

# 순열 : 순서가 중요, 모든 숫자를 한번씩 선택 DFS(num)
# 조합 : 순서가 중요하지 않음, 오름차순 유지 필요 DFS(num, cnt)
# 이전보다 더 큰 숫자만 선택해야 하므로 cnt를 활용해서 탐색 시작점을 제한해야 한다.