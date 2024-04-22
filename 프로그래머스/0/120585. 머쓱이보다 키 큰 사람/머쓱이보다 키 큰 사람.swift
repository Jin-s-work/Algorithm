import Foundation

func solution(_ array:[Int], _ height:Int) -> Int {
    
    var s = 0
    for k in array{
        if height < k{
            s += 1
        }
    }
    
    return s
}