

n = int(input())
arr = list(map(int, input().split()))
a, b, c, d = list(map(int, input().split()))
# + - * /

Max = -float('inf')
Min = float('inf')

def DFS(num, idx, plus, minus, mult, div):
    global Max, Min
    if idx == n - 1:
        Max = max(Max, num)
        Min = min(Min, num)
        return

    if plus > 0:
        DFS(num + arr[idx + 1] , idx + 1, plus - 1, minus, mult, div)
    if minus > 0:
        DFS(num - arr[idx + 1] , idx + 1, plus, minus - 1, mult, div)
    if mult > 0:
        DFS(num * arr[idx + 1] , idx + 1, plus, minus, mult - 1, div)
    if div > 0:
        if num < 0:
            DFS(-(abs(num) // arr[idx + 1]), idx + 1, plus, minus, mult, div - 1)
        else:
            DFS(num // arr[idx + 1] , idx + 1, plus, minus, mult, div - 1)

DFS(arr[0], 0, a, b, c, d)

print(Max)
print(Min)