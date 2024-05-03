def solution(tickets):
    answer = []
    
    check = [0] * len(tickets)
    def DFS(airport, path):
        if len(path) == len(tickets) + 1:
            answer.append(path)
            return
        
        
        for idx, ticket in enumerate(tickets):
            if ticket[0] == airport and not check[idx]:
                check[idx] = True
                DFS(ticket[1], path + [ticket[1]])
                check[idx] = False
        
        
    DFS("ICN", ["ICN"])
    answer.sort()
    
    return answer[0]