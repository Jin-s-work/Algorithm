# def solution(game_board, table):
#     answer = -1
    
    
    
    
    
    
#     return answer

import sys
from collections import deque

# 게임 보드에 빈 공간과 테이블에 있는 조각들의 좌표를 구한다.
def get_pieces(board, is_game_board):
    moves = ((0, 1), (0, -1), (1, 0), (-1, 0))
    pieces = []
    piece = 1 if is_game_board else 0
    for i in range(len(board)):
        for j in range(len(board)):
            if board[i][j] == piece:
                continue
            queue = deque([(i, j)])
            board[i][j] = piece
            pieces.append([])
            while queue:
                c_i, c_j = queue.popleft()
                pieces[-1].append((c_i, c_j))
                for move_i, move_j in moves:
                    new_i, new_j = c_i + move_i, c_j + move_j
                    if not 0 <= new_i < len(board) or not 0 <= new_j < len(board):
                        continue
                    if board[new_i][new_j] == piece:
                        continue
                    board[new_i][new_j] = piece
                    queue.append((new_i, new_j))
    return pieces

# 찾은 조각의 좌표를 이용해서 이차원 배열로 표현할 수 있는 함수
def get_shape(piece):
    min_r, min_c = sys.maxsize, sys.maxsize
    max_r, max_c = 0, 0
    for r, c in piece:
        min_r = min(r, min_r)
        min_c = min(c, min_c)
        max_r = max(r, max_r)
        max_c = max(c, max_c)
    n, m = max_r - min_r + 1, max_c - min_c + 1
    shape = [[0 for _ in range(m)] for _ in range(n)]
    for r, c in piece:
        shape[r - min_r][c - min_c] = 1
    return shape

# 이차원 배열을 90도씩 돌리는 함수
def turn_90(shape):
    n, m = len(shape[0]), len(shape)
    new_shape = [[0 for _ in range(m)] for _ in range(n)]
    for r in range(n):
        for c in range(m):
            new_shape[r][c] = shape[m - c - 1][r]
    return new_shape

def is_equal(p1, p2):
    p1_shape = get_shape(p1)
    p2_shape = get_shape(p2)
    attempt = 0
    while attempt < 4:
        if p1_shape == p2_shape:
            return True
        p2_shape = turn_90(p2_shape)
        attempt += 1
    return False

def solution(game_board, table):
    answer = 0
    g_pieces = get_pieces(game_board, True)
    t_pieces = get_pieces(table, False)
    used = set()
    for g_piece in g_pieces:
        for i, t_piece in enumerate(t_pieces):
            if len(g_piece) != len(t_piece) or i in used:
                continue
            if is_equal(g_piece, t_piece):
                answer += len(g_piece)
                used.add(i)
                break
    return answer