from itertools import permutations

def candidate():
    return [''.join(p) for p in permutations('123456789', 4)]

# 판정
def judge(guess, secret):
    s = sum(a == b for a, b in zip(guess, secret))
    b = len(set(guess) & set(secret)) - s
    return s, b

# 필터해서 일치하는 후보만 남김
def filter_cands(cands, guess, s, b):
    return [x for x in cands if judge(guess, x) == (s, b)]

# 다음 질문 선택,, 최대 묶음을 최소로
def pick_next(cands):
    best_g, best_score = None, 10**9
    for g in cands:
        bucket = {}
        for s in cands:
            key = judge(g, s)
            bucket[key] = bucket.get(key, 0) + 1
        score = max(bucket.values())
        if score < best_score:
            best_g, best_score = g, score
    return best_g

import re

def solution(n, submit):
    
    cands = candidate()
    guess = '1234'
    
    for _ in range(n):
        res = submit(int(guess))
        s, b = map(int, re.findall(r'\d+', res))
        if s == 4:
            return int(guess)
        cands = filter_cands(cands, guess, s, b)
        if len(cands) == 1:
            return int(cands[0])
        guess = pick_next(cands)
    
    # 전체 비밀번호 후보들을 다 만들어놓고 시작한다.
    # 거기에서 넣는 후보들을 넣어서 파악한다. 
    
    return int(guess)

# 숫자 4개 비밀번호 맞추는 게임
# 제출 기회가 총 n번인데 6정도로 생각하자
# 포함되어있지 않다면 OUT
# 포함되어있지만 위치 틀리면 BALL
# 포함되어있고 위치까지 정확하면 STRIKE



