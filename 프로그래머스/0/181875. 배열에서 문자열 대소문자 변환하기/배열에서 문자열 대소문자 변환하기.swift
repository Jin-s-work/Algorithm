import Foundation

func solution(_ strArr:[String]) -> [String] {
    
    var ans : [String] = []
    for (i, str) in strArr.enumerated(){
        if i % 2 == 0{
            ans.append(str.lowercased())
        }
        else{
            ans.append(str.uppercased())
        }
    }
    
    
    return ans
}