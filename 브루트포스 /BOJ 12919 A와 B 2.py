import sys
s = list(input())
t = list(input())

def DFS(t):
    if s == t:
        print(1)
        sys.exit()
    if len(t) == 0:   # 안되고 없어질 경우 0을 리턴
        return 0
    if t[-1] == 'A':  # 맨 뒤에가 A일 경우
        DFS(t[:-1])   # 맨 뒤를 없애준다.
    if t[0] == 'B':   # 맨 앞일 경우
        DFS(t[1:][::-1]) # B를 제거하고, 뒤집는다.
DFS(t)
print(0)
