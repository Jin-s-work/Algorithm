def solution(n):
    answer = 0
    
    num = bin(n).count("1")
    
    while True:
        n += 1
        if num == bin(n).count("1"):
            answer = n
            break
        
    
    return answer



# def solution(n):
#     answer = 0
    
#     num1 = 0
#     one = str(bin(n))
#     for i in one:
#         if i == '1':
#             num1+=1
    
    
#     num = n
#     while num <= 1000000:
#         num2 = 0
#         num+=1
#         two = str(bin(num))
#         for i in two:
#             if i == '1':
#                 num2+=1
#         if num1 == num2:
#             return num
        
        
    
    
#     return answer

