import Foundation

func solution(_ array:[Int], _ n:Int) -> Int {
    
    var num = 0
    for k in array{
        if k == n{
            num += 1
        }
    }
    
    return num
}