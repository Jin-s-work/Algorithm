

# 폭발 문자열을 포함하면 "모든" 폭발 문자열이 폭발
# 남은 문자열을 이어서 새로운 문제열 만든다.
# 새로 생긴 문자열에 포함이 되어있을 수도
# 폭팔은 폭발 문자열에 문자열에 없을때까지 계속

st = input()
bomb = input()

n = len(bomb)

arr = []
for k in st:
    arr.append(k)

    if ''.join(arr[-n:]) == bomb:
        del arr[-n:]

ans = ''.join(arr)
if ans == "":
    print("FRULA")
else:
    print(ans)
