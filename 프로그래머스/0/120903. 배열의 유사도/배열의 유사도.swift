import Foundation

func solution(_ s1:[String], _ s2:[String]) -> Int {
    
    var s = 0
    for k in s1{
        if s2.contains(k){
            s += 1
        }
    }
    
    return s
}