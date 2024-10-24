

st = input()

num = 0
if len(st) >= 10:
    num = 9 + (len(st) - 9) // 2
else:
    num = len(st)

check = [0] * (num + 1)
flag = False

def DFS(idx, ans):
    global flag
    if flag:
        return


    if idx == len(st):
        if len(ans) == num:
            print(" ".join(map(str, ans)))
            flag = True
        return
    # 처음에 나온 수를 바로 출력하므로 flag를 통해 다음 거는 안나오게 한다.

    # 일단 0이면 안되고, 숫자 자체도 제일 큰 수인 num보다 작아야 한다.
    # 또한 check를 통해 지나간 적 없는 숫자여야 한다.
    if int(st[idx:idx+1]) <= num and not check[int(st[idx:idx + 1])] and st[idx] != '0':
        check[int(st[idx:idx + 1])] = True
        DFS(idx + 1, ans + [st[idx:idx+1]])
        check[int(st[idx:idx + 1])] = False

    # 2자리수의 DFS를 진행할 때에는 2칸 뒤가 st를 넘으면 안되고 앞자리가 0이어도 안된다.
    # 그리고 똑같이 num보다 작은 경우와 check를 통해 지나간 적 없는지 확
    if idx + 1 < len(st) and st[idx] != '0':
        if int(st[idx:idx + 2]) <= num and not check[int(st[idx:idx + 2])]:
            check[int(st[idx:idx + 2])] = True
            DFS(idx + 2, ans + [st[idx:idx+2]])
            check[int(st[idx:idx + 2])] = False

DFS(0, [])

