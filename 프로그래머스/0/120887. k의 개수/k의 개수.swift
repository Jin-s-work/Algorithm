import Foundation

func solution(_ i:Int, _ j:Int, _ k:Int) -> Int {
    
    var ans = 0
    for idx in i...j{
        var num = idx
        while num > 0{
            if num % 10 == k{
                ans += 1
            }
            num /= 10
        }
    }
    
    return ans
}