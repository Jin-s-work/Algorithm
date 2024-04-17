from collections import Counter

def solution(str1, str2):
    answer = 0
    
    str1 = str1.upper()
    str2 = str2.upper()
    
    arr1 = []
    arr2 = []
    for i in range(len(str1)-1):
        if 'A' <= str1[i] <= 'Z' and 'A' <= str1[i+1] <= 'Z':
            arr1.append(str1[i] + str1[i+1])
    
    for i in range(len(str2)-1):
        if 'A' <= str2[i] <= 'Z' and 'A' <= str2[i+1] <= 'Z':
            arr2.append(str2[i] + str2[i+1])
    
    union = list((Counter(arr1) | Counter(arr2)).elements())
    inter = list((Counter(arr1) & Counter(arr2)).elements())
    
    if len(union) == 0 and len(inter) == 0:
        answer = 1
    else:
        answer = len(inter) / len(union)
    
    answer *= 65536
    answer = int(answer)
    
    return answer