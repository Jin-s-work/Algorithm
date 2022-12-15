import math
n = int(input())
arr = [0] * (n+1)
arr[1] = 1


for i in range(2, n+1):
    Min = 1001
    
    for j in range(1, int(math.sqrt(i)) + 1):
        Min = min(Min, arr[i - j*j])
        # i - j*j 즉 이 값이 몇개를 썼는지 표기해주는 것을
        # Min과 비교하여 더 작은 값을 넣어준다.
    
    arr[i] = Min + 1
    # 원래 +1을 해서 넣어야하는데 안넣어줬으므로 1 더해서 넣어줌
    
print(arr[n])