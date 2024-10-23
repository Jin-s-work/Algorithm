

# 한개의 모음과 최소 두개의 자음
# 증가하는 수열!

l, c = map(int, input().split())
arr = list(map(str, input().split()))
arr.sort()

ans = []

def DFS(idx, st, num1, num2):
    if num1 >= 1 and num2 >= 2 and len(st) == l:
        ans.append(st)
        return

    if idx == c:
        return

    if arr[idx] in ['a', 'e', 'i', 'o', 'u']:
        DFS(idx + 1, st + arr[idx], num1 + 1, num2)
    else:
        DFS(idx + 1, st + arr[idx], num1, num2 + 1)

    DFS(idx + 1, st, num1, num2)
    # 현재 문자를 선택하지 않고 다음 문자를 넘어가는 경우도 고려해야...!!!!!

    return

DFS(0, "", 0, 0)
for k in ans:
    print(k)

