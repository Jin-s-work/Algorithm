from collections import deque
def solution(board):
    answer = 0
    
    import sys
    def BFS(start):
        arr = [[sys.maxsize] * len(board[0]) for _ in range(len(board))]
        q = deque([start])
        arr[0][0] = 0

        dx = [-1,0,1,0]
        dy = [0,1,0,-1]
        n = len(board)
        m = len(board[0])

        while q:
            x, y, cost, d = q.popleft()

            for i in range(4):
                nx = x + dx[i]
                ny = y + dy[i]

                if 0<=nx<n and 0<=ny<m and board[nx][ny] == 0:
                    if i == d:
                        new_cost = cost + 100
                    else:
                        new_cost = cost + 600
                    
                    if new_cost < arr[nx][ny]:
                        arr[nx][ny] = new_cost
                        q.append((nx, ny, new_cost, i))
     
        return arr[-1][-1]
    
    answer = min(BFS((0,0,0,1)), BFS((0,0,0,2)))
    
    return answer

# 일반적인 BFS로 푼 다음에 각각의 블록에 일직선은 1, 코너는 5로 하면 될지도?