import sys
input = sys.stdin.readline

st = input().split('-')
# 이렇게 할 경우 만약 '55-50+40'일 때
# ['55', '50+40']이 된다.

ans = 0
# 처음 나오는 수가 아니다.. 만약 -가 없는 경우 모든 문자열이 st[0]에 있게 될 것이다.
# 중요한 포인트!
for k in st[0].split('+'):
    ans += int(k)
# 그 뒤에 나올때 +를 모두 빼고 다 빼준다..
for k in st[1:]:
    for l in k.split('+'):
        ans -= int(l)
# 이것의 경우 -가 만약 없다면 st[0].split('+')에서 다 더해지기 때문에 
# 여기 부분은 실행되지 않는다.

print(ans)


# st = input().rstrip()

# idx = st.find('-')

# # 만약 '-'가 없다면 모든 수를 더합니다.
# if idx == -1:
#     print(sum(map(int, st.split('+'))))
# else:
#     # '-' 이전까지의 부분은 모두 더하고, 이후의 부분은 모두 빼면 최소값
#     result = sum(map(int, filter(None, st[:idx].split('+')))) - sum(map(int, filter(None, st[idx+1:].split('+'))))
#     print(result)
    
# 밑은 쓸데없는 짓거리....
# 내가 생각하는 방법과 답이 똑같긴 하다
    
# check = False
# for k in st:
#     if k == '-':
#         check = True
    
#     if (check and k == '+'):
#         k = '-'

# print(st)
# ans = 0
# tmp = ""
# plus = False
# minus = False
# first = True
# idx = 0
# for k in st:
#     if k >= '0' and k <= '9':
#         tmp += k
#     else:
#         if k == '+':
#             if plus:
#                 ans += int(tmp)
#                 tmp = ""
#                 plus = False
#             elif minus:
#                 ans -= int(tmp)
#                 tmp = ""
#                 minus = False
#             elif first:
#                 ans += int(tmp)
#                 first = False
                
#             plus = True
            
#         elif k == '-':
#             if plus:
#                 ans += int(tmp)
#                 tmp = ""
#                 plus = False
#             elif minus:
#                 ans -= int(tmp)
#                 tmp = ""
#                 minus = False
#             elif first:
#                 ans += int(tmp)
#                 first = False
                
#             minus = True
            
#     if idx == len(st) - 1:
#         if plus:
#             ans += int(tmp)
#         elif minus:
#             ans -= int(tmp)

#     idx += 1

# print(ans)