import Foundation

func solution(_ n:Int) -> [Int] {
    
    var arr : [Int] = []
    for i in 1...n{
        if i % 2 != 0{
            arr.append(i)
        }
    }
    
    return arr
}