s = str(input())
ans = ""

for i in range(0, len(s)):
    if i == 0:
        if s[i] == '0':
            ans += '0'
        else:
            ans += '1'
    else:
        if s[i] != s[i-1]:
            if s[i] == '0':
                ans += '0'
            else:
                ans += '1'

num1 = 0
num0 = 0
for k in ans:
    if k == '0':
        num0 += 1
    else:
        num1 += 1
if num0 >= num1:
    print(num1)
else:
    print(num0)    
