
n, m, v = map(int, input().split())
arr = [[0] * (n+1) for i in range(n+1)]
# arr로 그래프를 만들어 준다. 크기를 위해 n+1씩 해준다.
check = [0] * (n+1)
# 방문했는지 확인하는 배열도  (n+1)로 한다.

for i in range(m):
    a, b = map(int, input().split())
    arr[a][b] = arr[b][a] = 1
    # 입력 받고 c++처럼 1로 넣어준다.

def DFS(v):
    check[v] = 1
    print(v, end = ' ')
    # v가 시작 정점 번호 이므로 check에 체크를 하고, 뛰어서 출력한다.
    
    # 1부터 n까지 관하여
    for i in range(1, n+1):
        if(check[i] == 0 and arr[v][i] == 1):
            DFS(i)
        # check가 방문하지 않았고, arr가 1일 경우에 DFS로 들어간다.
        
def BFS(v):
    queue = [v]
    # 큐에 처음 v가 있다고 가정하고 시작한다.
    check[v] = 0
    # check로 v는 0으로 한다. (DFS를 완료한 상태이므로 없애주어야 하기에)
    ## 즉 여기서는 false가 지난것을 표시한다.
    while queue:
        v = queue.pop(0)
        print(v, end = ' ')
        for i in range(1, n+1):
            if (check[i] == 1 and arr[v][i] == 1):
                queue.append(i)
                check[i] = 0
            # 1-n에 관하여 check가 1일 경우 (아직 방문하지 않았을때)
            # 그리고 arr가 1인 경우에 queue에 새로운 i를 넣어주고 방문한 표시인
            # 0을 입력한다.
DFS(v)
print()
BFS(v)

