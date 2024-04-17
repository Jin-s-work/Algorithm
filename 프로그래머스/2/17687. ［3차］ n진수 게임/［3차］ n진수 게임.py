
def convert(num, base):
    tmp = "0123456789ABCDEF"
    q, r = divmod(num, base)
    
    # q가 0인 경우에는 바로 출력한다. 몫이 0이므로
    if q == 0:
        return tmp[r]
    else:
        return convert(q, base) + tmp[r]
    # 0이 아닐 경우에는 몫과 진수에 관하여 convert를 다시하고 거기에 tmp[r]를 추가

def solution(n, t, m, p):
    answer = ''
    
    # n진법, 구하는 숫자의 개수 t
    # 게임 참가인원 m, 튜브의 순서 p
    
    arr = ""
    for i in range(m * t):
        arr += str(convert(i, n))
    # arr에 m * t 즉 모든 단어들을 찾아서 arr에 넣어준다.
    # 총 횟수만큼
    
    # 아직 t에 도달하기 전까지 answer에 튜브의 순서만큼을 더한다.
    # 0이 아니라 1부터이기에 1씩 빼서 더해준다.
    while len(answer) < t:
        answer += arr[p-1]
        p += m
    
    
    return answer