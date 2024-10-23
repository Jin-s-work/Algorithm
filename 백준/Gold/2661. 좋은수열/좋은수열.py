


n = int(input())

def bad(st):
    for i in range(1, len(st) // 2 + 1):
        if st[-i:] == st[-2 * i : -i]:
            return True
    return False
# 끝에서부터 i길이의 두 개의 부분 수열이 같으면 나쁜 수열이다.
# st[-i:] : 수열의 마지막에서부터 길이 i만큼의 부분 수열
# st[-2*i:-i] : 수열에서 그 이전의 i만큼의 부분 수열


def DFS(st):
    if len(st) == n:
        print(st)
        exit()

    for next in '123':
        if not bad(st + next):
            DFS(st + next)
    # 여기에서 123을 차례대로 붙여가면서 재귀적으로 넣어준다.
    # 붙여주는 과정에서 나쁜 수열이 되는 경우에는 뒤에는 볼 필요가 없기에 여기에서 걸러준다.
# 순서대로 차례대로 붙여주는 과정에서 제일 먼저 나온 것이 사전순으로 제일 먼저 이기에 바로 출력하고 끝낸다.

DFS("")

