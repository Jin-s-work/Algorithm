import Foundation

func solution(_ array:[Int]) -> Int {
    
    var ans = 0
    for k in array{
        var num = k
        while num > 0{
            if num % 10 == 7{
                ans += 1
            }
            num /= 10
        }
        
    }
    
    return ans
}