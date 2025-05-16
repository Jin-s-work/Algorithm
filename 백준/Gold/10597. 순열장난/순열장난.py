

st = input()

if len(st) >= 10:
    num = 9 + (len(st) - 9) // 2
else:
    num = len(st)

check = [0] * (num + 1)
flag = False

def DFS(idx, path):
    global flag
    if flag:
        return
    # 한번 출력했으면 리턴해서 나온다!

    if idx == len(st):
        if len(path) == num:
            print(" ".join(map(str, path)))
            flag = True
        return

    # 1자리 숫자 구하기
    if idx < len(st):
        one = int(st[idx])
        # 한자리 수의 경우 앞 자리수가 0인거는 상관없고 그 자체만 0이 아니면 된다.
        if one != 0 and not check[one]:
            check[one] = True
            DFS(idx + 1, path + [one])
            check[one] = False

    # 2자리 숫자 구하기
    if idx+ 1 < len(st):
        two = int(st[idx : idx + 2])
        if st[idx] != '0' and two <= num and not check[two]:
            check[two] = True
            DFS(idx + 2, path + [two])
            check[two] = False

DFS(0, [])




