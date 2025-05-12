

import sys
input = sys.stdin.readline

s = input().strip()
q = int(input())

prefix = {chr(c) : [0] * (len(s) + 1) for c in range(ord('a'), ord('z') + 1)}
# 각각 단어에 대해서 딕셔너리로 만들기

for i in range(len(s)):
    for c in prefix:
        prefix[c][i + 1] = prefix[c][i] + (1 if s[i] == c else 0)
# 알파벳이 c일 경우에 [c]에 대해서 다음 부분을 늘려서 더해준다.
# i range(len(s) 다음에 for c in prefix를 해서 알파벳이 없는 경우에도 넘어가면서
# 계속 이어주어야 한다.

for _ in range(q):
    ch, l, r = input().split()
    l = int(l)
    r = int(r)
    print(prefix[ch][r + 1] - prefix[ch][l])
# 알파벳 ch에 대해서 r+1 - l