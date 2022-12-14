

def DFS(num, digit):
    global ans  # ans를 받아주는 것이 없으니 gloabl로
    if num > n:
        return  # num이 더 클 경우 리턴한다.
    ans = max(ans, num)
    # 더 큰 값이 나올 경우 갱신
    
    for i in range(len(arr)):
        DFS(num + digit * arr[i], digit * 10)
    # num에 digit과 함께 arr[i]를 곱하고 digit은 10배해서 넘어감
    
n, k = map(int, input().split())
arr = list(map(int, input().split()))
ans = 0

DFS(0, 1)
# num은 0, digit은 1로 시작한다.
print(ans)
