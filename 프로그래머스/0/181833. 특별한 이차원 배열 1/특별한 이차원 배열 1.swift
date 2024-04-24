import Foundation

func solution(_ n:Int) -> [[Int]] {
    
    var arr : [[Int]] = []
    
    for i in 0..<n{
        var tmp : [Int] = []
        for j in 0..<n{
            if i == j{
                tmp.append(1)
            }
            else{
                tmp.append(0)
            }
        }
        arr.append(tmp)
        
    }
    
    return arr
}