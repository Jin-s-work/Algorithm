

n = int(input())

# 길이가 인접한 두개의 부분 수열

def is_good(word):
    for i in range(1, len(word) // 2 + 1):
        # 마지막 i개와 그 앞의 i개를 비교
        # for문을 통해서 i를 늘려준다.
        if word[-i:] == word[-2 * i : -i]:
            return False
    return True

def DFS(st):
    if len(st) == n:
        print(st)
        exit()
    # 1, 2, 3
    # 숫자를 먼저 탐색하고 나쁜 수열이 아닐 때 들어가주는 것이 훨씬 복잡도를 줄일 수 있다.
    for i in range(1, 4):
        if is_good(st + str(i)):
            DFS(st + str(i))

DFS("")