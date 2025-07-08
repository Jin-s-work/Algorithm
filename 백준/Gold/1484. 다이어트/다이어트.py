

g = int(input())

now = 2
past = 1
ans = []
check = False
while now <= 100000:


    if (now + past) * (now - past) == g:
        ans.append(now)
        check = True
    if (now + past) * (now - past) > g and now - past == 1:
        break
    # 합은 g를 넘는 데 하나 차이가 나는 경우 -> 다음 스텝은 같아지기에 break
    if (now + past) * (now - past) > g:
        past += 1
    else:
        now += 1

if check:
    for k in ans:
        print(k)
else:
    print(-1)