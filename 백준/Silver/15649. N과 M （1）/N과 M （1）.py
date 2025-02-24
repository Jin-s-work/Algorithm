

n, m = map(int, input().split())

check = [0] * (n + 1)
arr = [0] * (n + 1)
def DFS(num):
    if num == m:
        for i in range(m):
            print(arr[i], end = " ")
        print()
        return

    for i in range(1, n + 1):
        if not check[i]:
            arr[num] = i
            check[i] = True
            DFS(num + 1)
            check[i] = False

    # 들어가서 num이 m을 달성한 경우에는 거기까지의 자취를 출력
    # return 해서 나와서 다시 False로 하고 되돌아간다
    # 그리고 check[i]가 아직 방문되지 않으 arr[num]을 갱신해주고 또 들어간다.
    # 이를 반복

DFS(0)