

n = int(input())
m = int(input())

arr = []
for i in range(n):
    tmp = list(map(int, input().split()))
    arr.append(tmp)

city = list(map(int, input().split()))
group = [-1] * n
num = 0
check = [0] * n


def DFS(now, group_num):
    # 들어가서는 check를 하고 group에 num을 넣어준다.
    check[now] = True
    group[now] = num
    for i in range(n):
        if arr[now][i] == 1 and not check[i]:
            DFS(i, group_num)
            # 갈 수 있으면 DFS로 같은 group_num으로 들어가준다.

for i in range(n):
    if not check[i]:
        DFS(i, num)
        num += 1
    # DFS를 할 때마다 group_num을 올려주며 각각 분리

first_num = group[city[0] - 1]
# 제일 처음인 city를 group 몇번인지 확인한후에
for k in city:
    if group[k-1] != first_num:
        print("NO")
        break
else:
    print("YES")
# 루프가 그냥 종료 되었을때는 YES