

t = int(input())
# 그냥 자체로 회문 : 0
# 하나를 지워서 회문이 되면 1
# 그 외는 2

def is_pal(s, left, right):
    while left <= right:
        if s[left] != s[right]:
            return False
        left += 1
        right -= 1
    return True

def find(s):
    left = 0
    right = len(s) - 1

    # 이분탐색을 통해서 다른 값이 있을 때 왼쪽에서 넘어가거나 오른쪽에서 줄어드는 방식으로
    # true가 나올 경우에는 1 아닐 경우에는 2이다.
    # 이와 같이 이분탐색을 진행했는데 return 되지 않으면 그냥 팰린드롬이라 0을 리
    while left <= right:
        if s[left] != s[right]:
            if is_pal(s, left + 1, right) or is_pal(s, left, right - 1):
                return 1
            else:
                return 2
        left += 1
        right -= 1
    return 0



for i in range(t):
    st = input()

    print(find(st))
