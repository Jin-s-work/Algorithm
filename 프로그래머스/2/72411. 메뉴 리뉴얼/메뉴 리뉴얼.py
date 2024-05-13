from itertools import combinations
from collections import Counter

def solution(orders, course):
    answer = []
    
    for k in course:
        arr = []
        for order in orders:
            comb = combinations(sorted(order), k)
            arr += comb
    
        counter = Counter(arr)
        if len(counter) != 0 and max(counter.values()) != 1:
            answer += [''.join(i) for i in counter if counter[i] == max(counter.values())]
        
    
    return sorted(answer)


# from itertools import combinations
# from collections import Counter

# def solution(orders, course):
#     answer = []
    
#     # 손님들의 주문 내역 중 중복되는 조합을 찾아서 course의 수를 개수로 하는 코스요리를 만드는 것
#     # combinations('ABCD', 2) -> [(A, B), (A, C), (A, D), (B, C), (B, D), (C, D)]
#     # permutations는 순서를 고려하지만 여기서는 순서 고려하지 않는다.
    
#     for k in course:
#         arr = []
#         for order in orders:
#             comb = combinations(sorted(order), k)
#             # comb에 sorted(order)의 조합들이 저장된다 (k개)
#             arr += comb
#             # 이를 arr에 각각 더해준다.
        
#         # 이러면 arr에 order의 조합들이 저장된다.
#         counter = Counter(arr)
#         # 알파벳 개수를 세어준다. 즉 arr가 몇 개 있는지 세어준다.
#         # [(A,B),(A,B),(A,C), (A,D) ,(B,C) ,(B,D), (C,D)]에서
#         # {(A, B) : 2, (A, C) : 1, (A, D) : 1, (B, C) : 1, (B, D) : 1, (C, D) : 1} 와 같이 딕셔너리 형태로 반환한다.
        
#         # value의 최대가 1이면 안된다. counter의 길이가 0이어도 안된다. 
#         if len(counter) != 0 and max(counter.values()) != 1:
#             answer += [''.join(i) for i in counter if counter[i] == max(counter.values())]
#             # counter로 받아 딕셔너리로 반환된 값들을 2개 이상 세어진 것들을 출력한다.
#             # counter[i]가 counter.values()의 max일때 join해준다.
    
#     return sorted(answer)


