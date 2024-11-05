


n = int(input())
st = list(input())

ans = 0
for i in range(n-1):
    compare = st[:]
    word = input()
    num = 0
    
    for k in word:
        if k in compare:
            compare.remove(k)
        else:
            num += 1
    # 찾는 단어를 탐색하면서 그 단어가 첫번째 단어에 있다면 그 단어를 지워준다.
    # 없다면 num을 증가시켜 준다.
    
    # 여기에서 num은 차이
    if num < 2 and len(compare) < 2:
        ans += 1
    # 차이가 2보다 작고, 비교하는 부분이 2개 미만으로 남아있으면 개수 늘려주기

print(ans)