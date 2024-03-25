




def find(k):
    while k >= 5:
        if (k - 2) % 5 == 0:
            return False
        k //= 5
    
    return k != 2

def solution(n, l, r):
    answer = 0
    
    for k in range(l-1, r):
        if find(k):
            answer += 1
    
    return answer


# 1
# 11011
# 11011 11011 00000 11011 11011

# 왜인지는 모르겠지만 틀린 풀이

# def find(n, k):
#         if n == 1:
#             if k <= 2:
#                 return k-1
#             else:
#                 return k
        
#         div = 5 ** (n-1)
#         mul = 4 ** (n-1)
#         idx = k // div
#         # 5로 나누었을때의 나머지 01234
        
#         if k % div == 0:
#             idx -= 1
        
#         if idx < 2: # "11" 011
#             return mul * idx + find(n-1, idx * div)
#         elif idx == 2:
#             return mul * idx
#         else:  # 11 0 "11"
#             return mul * (idx - 1) + find(n-1, k - idx * div)
    