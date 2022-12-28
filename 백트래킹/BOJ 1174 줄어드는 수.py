n = int(input())

arr = []
res = set()

def DFS():
    global arr
    global res
    if arr:
        res.add(int("".join(map(str, arr))))
    # arr가 비어있지 않으면 res에 arr들을 이어서 넣어준다.
    
    # arr이 비어있거나, 제일 마지막이 i보다 클 경우
    # arr에 i를 넣어주고 DFS
    for i in range(10):
        if not arr or arr[-1] > i:
            arr.append(i)
            DFS()
            arr.pop()
DFS()
# ㅣist로 바꾸고 정렬해준다.
res = list(res)
res.sort()

# res의 길이가 n 이상일 경우 n-1번째를 프린트
if len(res) >= n:
    print(res[n-1])
else:
    print(-1)
