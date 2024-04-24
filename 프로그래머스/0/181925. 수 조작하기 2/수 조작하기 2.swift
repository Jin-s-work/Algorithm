import Foundation

func solution(_ numLog:[Int]) -> String {
    
    var ans = ""
    var num = numLog[0]
    for i in 0..<numLog.count-1{
        if numLog[i+1] - numLog[i] == 1{
            ans.append("w")
        }
        else if numLog[i+1] - numLog[i] == -1{
            ans.append("s")
        }
        else if numLog[i+1] - numLog[i] == 10{
            ans.append("d")
        }
        else if numLog[i+1] - numLog[i] == -10{
            ans.append("a")
        }
    }
    
    return ans
}