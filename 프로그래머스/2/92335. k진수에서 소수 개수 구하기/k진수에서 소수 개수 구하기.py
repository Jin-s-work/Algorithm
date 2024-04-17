import math
def solution(n, k):
    answer = 0
    
    st = ""
    while n:
        st += str(n % k)
        n //= k
    st = st[::-1]
    
    def sosu(num):
        if num == 0 or num == 1:
            return False
        for i in range(2, int(math.sqrt(num) + 1)):
            if num % i == 0:
                return False
        return True
    
    arr = st.split("0")
    for k in arr:
        if len(k) == 0:
            continue
        if sosu(int(k)):
            answer += 1
    
#     tmp = ""
#     for i in range(len(st)):
#         if st[i] != '0':
#             tmp += st[i]
#         else:
#             tmp = int(tmp)
#             if sosu(tmp):
#                 answer += 1
#                 tmp = ""
    
    
    return answer