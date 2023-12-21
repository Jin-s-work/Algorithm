import sys
input = sys.stdin.readline

from collections import deque

n, m, v = map(int, input().split())

arr = [[False] * (n+1) for _ in range(n+1)]
# 이차원 배열 만들때는 이런 식으로

for _ in range(m):
    a, b = map(int, input().split())
    arr[a][b] = 1
    arr[b][a] = 1
    
check1 = [False] * (n+1)
check2 = [False] * (n+1)
# 각각 BFS DFS 이다.

def DFS(v):
    check1[v] = True
    print(v, end = " ")
    for i in range(1, n+1):
        if not check1[i] and arr[v][i] == 1:
            DFS(i)
# DFS는 일단 들어가는 v를 True로 하고 v를 출력한다.
# check가 false이고, 즉 방문하지 않았고, v에서 i로 가는 것이 1일 경우
# 그 i로 들어간다.
            
def BFS(v):
    q = deque([v])
    check2[v] = True
    while q:
        v = q.popleft()
        print(v, end = " ")
        for i in range(1, n+1):
            if not check2[i] and arr[v][i] == 1:
                q.append(i)
                check2[i] = True
# BFS는 deque를 사용해야 한다.
# 똑같이 True로 해주고 q에 관해서 while문
# q 에서 popleft로 제일 앞에 하나 빼주고 v에 저장
# 그 v를 출력하고 위와 같이 아직 방문하지 않았고, 이어져 있을 경우
# 새로 q에 i를 넣어주고 True로 만들어준다.

DFS(v)
print()
BFS(v)


