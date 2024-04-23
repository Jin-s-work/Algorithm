import Foundation

func solution(_ names:[String]) -> [String] {
    
    var ans : [String] = []
    for (idx, name) in names.enumerated(){
        if idx % 5 == 0{
            ans.append(name)
        }
    }
    
    return ans
}