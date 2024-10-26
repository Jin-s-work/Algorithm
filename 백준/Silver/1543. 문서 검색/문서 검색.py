


word = input()
st = input()

check = [0] * 251

cnt = 0
idx = 0
n = len(st)

while idx <= len(word) - n:
    if word[idx:idx+n] == st:
        cnt += 1
        idx += n
    else:
        idx += 1

print(cnt)