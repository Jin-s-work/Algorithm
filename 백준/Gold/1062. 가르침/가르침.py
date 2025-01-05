

n, k = map(int, input().split())
# n개의 줄에 남극 언어의 단어가 주어진다.
# anta로 시작하고 tica로 끝난다.

if k < 5:
    print(0)
    exit()
elif k == 26:
    print(n)
    exit()

ans = 0
alp = [0] * 26
arr = []
for _ in range(n):
    w = input()
    arr.append(set(w))

for c in ('a', 'n', 't', 'i', 'c'):
    alp[ord(c) - ord('a')] = 1

def DFS(idx, num):
    global ans
    if num == k - 5:
        cnt = 0
        for word in arr:
            check = True
            for w in word:
                if not alp[ord(w) - ord('a')]:
                    check = False
                    break
                # 하나라도 안되는 경우가 있다면 check를 false로 해서 세지 않고 멈춘다.
            if check:
                cnt += 1
        # 각각의 경우에서

        ans = max(ans, cnt)
        return
    # 들어가다가 결국 num이 k-5가 되었을때, cnt를 늘려준다.
    # 그러면서 제일 큰 cnt를 구해준다.

    for i in range(idx, 26):
        if not alp[i]:
            alp[i] = True
            DFS(i, num + 1)
            alp[i] = False
    # 이렇게 들어가면서 alp에 true가 k-5개가 될때 계산해주는 것이다.

DFS(0,0)
print(ans)