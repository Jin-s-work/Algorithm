
import sys
n = int(input())
arr = list(map(int, input().split()))

plus, minus, mult, div = map(int, input().split())

Max = -sys.maxsize
Min = sys.maxsize

def DFS(num, idx, plus, minus, mult, div):
    global Max, Min
    if idx == n:
        Max = max(Max, num)
        Min = min(Min, num)
        return

    if plus > 0:
        DFS(num + arr[idx], idx + 1, plus - 1, minus, mult, div)
    if minus > 0:
        DFS(num - arr[idx], idx + 1, plus, minus - 1, mult, div)
    if mult > 0:
        DFS(num * arr[idx], idx + 1, plus, minus, mult - 1, div)
    if div > 0:
        if num < 0:
            DFS(-((-num) // arr[idx]), idx + 1, plus, minus, mult, div - 1)
        else:
            DFS(num // arr[idx], idx + 1, plus, minus, mult, div - 1)

DFS(arr[0], 1, plus, minus, mult, div)
print(Max)
print(Min)

