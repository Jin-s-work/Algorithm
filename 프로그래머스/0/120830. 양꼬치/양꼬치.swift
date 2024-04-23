import Foundation

func solution(_ n:Int, _ k:Int) -> Int {
    
    var ans = n * 12000 + 2000 * (k - (n / 10))
    
    return ans
}