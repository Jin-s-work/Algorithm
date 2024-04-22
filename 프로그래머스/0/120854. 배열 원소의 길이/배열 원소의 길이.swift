import Foundation

func solution(_ strlist:[String]) -> [Int] {
    
    var arr : [Int] = []
    for k in strlist{
        arr.append(k.count)
    }
    
    return arr
}