from itertools import permutations
arr = list(permutations([1,2,3,4,5,6,7,8,9], 3))
# 숫자로 만들수 있는 순열을 모두 넣어준다.
# 순서를 고려해서 만들어준다.

n = int(input())
# 세자리가 동일하면 스트라이크 숫자가 있으나 다른 자리에 위치하면 볼
for _ in range(n):
    num, st, ba = map(int, input().split())
    num = list(str(num))
    cnt = 0
    
    for i in range(len(arr)):
        strike = 0
        ball = 0
        i -= cnt
        # cnt는 없애는 숫자 만큼 다시 앞으로 와서 다시 검사한다.
        
        for j in range(3):
            num[j] = int(num[j])
            if num[j] in arr[i]:  # 숫자가 arr에 있고
                if j == arr[i].index(num[j]):
                    strike += 1
                # index또한 j와 같을 경우 strike 표시
                else:
                    ball += 1
                # index는 다를 경우 ball을 표시
        
        # 둘의 값이 원래와 다를 경우 아니므로 지운다..
        if strike != st or ball != ba:
            arr.remove(arr[i])
            cnt += 1

print(len(arr))