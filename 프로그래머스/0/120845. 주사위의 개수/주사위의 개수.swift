import Foundation

func solution(_ box:[Int], _ n:Int) -> Int {
    
    var s = 1
    for k in box{
        s *= (k / n)
    }
    
    return s
}