import sys
sys.setrecursionlimit(10**6)
input = sys.stdin.readline


from collections import deque

n = int(input())

def round_new(n):
    return int(n) + (1 if n - int(n) >= 0.5 else 0)

arr = []
for _ in range(n):
    a = int(input())
    arr.append(a)
    
arr.sort()

num = len(arr)
ex  = round_new(num * 0.15)

ans = []
for i in range(ex, num - ex):
    ans.append(arr[i])

if len(arr) == 0:
    print(0)
else:
    print(round_new(sum(ans) / len(ans)))
