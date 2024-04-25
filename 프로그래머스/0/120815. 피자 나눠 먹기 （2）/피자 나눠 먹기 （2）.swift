import Foundation

func solution(_ n:Int) -> Int {
    
    var ans = 0
    for i in 1...101{
        if (6 * i) % n == 0{
            ans = i
            break
        }
    }
    
    return ans
}