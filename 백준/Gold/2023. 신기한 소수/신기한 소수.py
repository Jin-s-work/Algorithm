
import math
n = int(input())

def sosu(num):
    if num < 2:
        return False
    for i in range(2, int(math.sqrt(num)) + 1):
        if num % i == 0:
            return False
    return True

def DFS(num, length):
    if length == n:
        print(num)
        return

    # digit을 추가할때는 홀수만 추가해야 한다. 짝수는 소수 자체가 불가능하기에
    for digit in [1, 3, 7, 9]:
        # next는 원래의 num을 앞으로 해주고, digit을 추가하면서 확인한다.
        next = num * 10 + digit
        if sosu(next):
            DFS(next, length + 1)

# 한자리의 소수부터 시작해서 들어간다.
for start in [2, 3, 5, 7]:
    DFS(start, 1)

# 아무래도 8자리이기때문에 모든 수를 조사하면 시간복잡도가 늘어나기에 소수들을 추가하는 방식이 좋다..