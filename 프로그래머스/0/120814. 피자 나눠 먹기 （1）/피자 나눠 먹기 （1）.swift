import Foundation

func solution(_ n:Int) -> Int {
    
    var s = 0
    if n % 7 == 0{
        s = n / 7
    }
    else{
        s = n / 7 + 1
    }
    
    return s
}