import Foundation

func solution(_ emergency:[Int]) -> [Int] {
    
    var arr = emergency
    arr.sort(by : >)
    
    var ans : [Int] = []
    for k in emergency{
        if let idx = arr.firstIndex(of : k){
            ans.append(idx + 1)
        }    
    }
    
    return ans
}