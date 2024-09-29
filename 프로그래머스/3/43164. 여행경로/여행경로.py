def solution(tickets):
    answer = []
    
    check = [0] * len(tickets)
    def DFS(airport, path):
        if len(tickets) + 1 == len(path):
            answer.append(path)
            return
        
        for idx, ticket in enumerate(tickets):
            if airport == ticket[0] and not check[idx]:
                check[idx] = 1
                DFS(ticket[1], path + [ticket[1]])
                check[idx] = 0
    
    
    DFS("ICN", ["ICN"])
    
    answer.sort()
    
    return answer[0]