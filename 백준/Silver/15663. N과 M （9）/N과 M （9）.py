

n, m = map(int, input().split())
arr = list(map(int, input().split()))
arr.sort()

ans = []
check = [0] * n

def DFS(num):
    if len(ans) == m:
        for i in range(m):
            print(ans[i], end = " ")
        print()
        return

    tmp = 0
    for i in range(n):
        if not check[i] and arr[i] != tmp:
            ans.append(arr[i])
            check[i] = True
            tmp = arr[i]
            DFS(i)
            check[i] = False
            ans.pop()
        # check로 false하고, ans.pop으로 제거하여 원래 상태
        # 처음에는 ans에 넣고 check는 true로 해서 ans에 중복된 값이 안들어가게 한다.
        # if 문으로 체크할 때도 check를 통해 중복을 확인하고,
        # tmp를 통해 같은 레벨에서 중복된 값이 다시 선택되게 하지 않는다.
        # sort를 해서 가능한듯

DFS(0)