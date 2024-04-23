import Foundation

func solution(_ numbers:[Int], _ n:Int) -> Int {
    
    var num = 0
    var idx = 0
    while true{
        if num > n{
            break
        }
        num += numbers[idx]
        idx += 1
    }
    
    return num
}