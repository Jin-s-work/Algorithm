def solution(tickets):
    answer = []
    
    check = [0] * len(tickets)
    
    def DFS(airport, path):
        if len(path) == len(tickets) + 1:
            answer.append(path)
            return
        
        for idx, ticket in enumerate(tickets):
            if airport == ticket[0] and not check[idx]:
                check[idx] = True
                DFS(ticket[1], path + [ticket[1]])
                check[idx] = False
            # 방문하지 않은 경우 모든 경우에 대해서 DFS를 돌린다.
        
    DFS("ICN", ["ICN"])
    
    answer.sort()
    
    return answer[0]