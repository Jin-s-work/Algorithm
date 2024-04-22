import Foundation

func solution(_ n:Int) -> Int {
    
    var s = 2
    for i in 1...n{
        if i * i == n{
            s = 1
        }
    }
    
    return s
}