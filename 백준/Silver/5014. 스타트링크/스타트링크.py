import sys
sys.setrecursionlimit(10**6)
input = sys.stdin.readline


from collections import deque


f, s, g, u, d = map(int, input().split())
# f는 건물 전체 층
# s는 강호의 위치
# g는 스타트링크의 위치
# u는 위로 d는 아래로

check = [0 for _ in range(f+1)]
arr = [0 for _ in range(f+1)]

def BFS(start):
    q = deque([start])
    check[start] = 1
    
    while q:
        num = q.popleft()
        if num == g:
            return arr[g]
        # 한번에 갈 수 있는 두개 중에서 다 한개씩 증가시켜서 넣어주기
        # i가 전체 층 사이에 있고 아직 방문 안했을 경우
        # (start+u, start-d)로 하면 두 경우에만 이다.
        for i in (num+u, num-d):
            if (0<i<=f) and not check[i]:
                check[i] = 1
                arr[i] = arr[num] + 1
                q.append(i)
        # pop한 값인 num을 안쓰고 계속 start를 쓰고 있었다 바보
    
    if arr[g] == 0:
        return "use the stairs"

print(BFS(s))

