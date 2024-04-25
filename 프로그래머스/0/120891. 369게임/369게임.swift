import Foundation

func solution(_ order:Int) -> Int {
    
    var ans = 0
    var num = order
    
    while num > 0{
        let digit = num % 10
        if digit == 3 || digit == 6 || digit == 9{
            ans += 1
        }
        num /= 10
    }
    
    return ans
}