n = int(input())
arr = list(map(int, input().split()))
op = list(map(int, input().split()))

Max = -1e9
Min = 1e9

def DFS(depth, total, plus, minus, multiple, divide):
    global Max, Min
    if depth == n:
        Max = max(total, Max)
        Min = min(total, Min)
        return
    
    # 이 순서로 해도 될까..?
    if plus:
        DFS(depth+1, total+arr[depth], plus-1, minus, multiple, divide)
    if minus:
        DFS(depth+1, total-arr[depth], plus, minus-1, multiple, divide)
    if multiple:
        DFS(depth+1, total*arr[depth], plus, minus, multiple-1, divide)
    if divide:
        DFS(depth+1, int(total /arr[depth]), plus, minus, multiple, divide-1)

DFS(1, arr[0], op[0], op[1], op[2], op[3])
print(Max)
print(Min)
