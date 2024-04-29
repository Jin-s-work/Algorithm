def solution(arr):
    answer = [[]]
    rows = len(arr)
    cols = len(arr[0]) if rows > 0 else 0
    
    if rows > cols:
        # 행의 수가 더 많은 경우, 모든 행에 충분한 0을 추가
        additional_zeros = rows - cols
        for row in arr:
            row.extend([0] * additional_zeros)
    elif cols > rows:
        # 열의 수가 더 많은 경우, 필요한 만큼의 새 행을 추가
        additional_rows = cols - rows
        for _ in range(additional_rows):
            arr.append([0] * cols)
    
    return arr
#     answer = arr
    
#     if len(answer) > len(answer[0]):
#         for k in answer:
#             k.append(0)
#     elif len(answer) < len(answer[0]):
#         num = len(answer[0]) - len(answer)
#         for i in range(num):
#             answer.append([0] * len(answer[0]))
    
    
#     return answer