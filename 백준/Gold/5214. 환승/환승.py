import sys
# sys.setrecursionlimit(10**6)
input = sys.stdin.readline


from collections import deque


n, k, m = map(int, input().split())

station = [[] for _ in range(n)]
hyper = [[] for _ in range(m)]

for i in range(m):
    stop = list(map(int, input().split()))
    for k in stop:
        station[k-1].append(i)
        hyper[i].append(k-1)
        # hyper들에는 역들을 넣어주고
        # station의 각각 에는 i를 계속 넣어준다.
    
# 역들이 많아질 수록 하나하나 true를 해주려면 시간복잡도가 커질 거 같은데 어떻게 해결할까..?

def BFS():
    check_station = [0] * n
    check_hyper = [0] * m
    q = deque([(0,1)]) # 현재역, 방문횟수
    check_station[0] = True
    
    while q:
        now, num = q.pop()
        next = []
        
        # 스테이션을 검사할때 아직 방문하지 않으면 next에 넣어준다.
        for h_idx in station[now]:
            if not check_hyper[h_idx]:
                next.append(h_idx)
                check_hyper[h_idx] = True
        
        # next도 검사 next 중에 찾아서 방문 하지 않았을 경우에
        # 또 거기서 n-1에 도착하면 프린트하고 리턴해준다.
        for hyp in next:
            for stop in hyper[hyp]:
                if not check_station[stop]:
                    if stop == n-1:
                        print(num + 1)
                        return
                    check_station[stop] = True
                    q.appendleft((stop, num+1))
                    # 큐에 넣을때에도 (stop, num+1)d을 넣는다.
                    # (현재역, 방문횟수)
    print(-1)
    
if n == 1:
    print(1)
else:
    BFS()