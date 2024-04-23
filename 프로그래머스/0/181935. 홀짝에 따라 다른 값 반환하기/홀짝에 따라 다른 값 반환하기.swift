import Foundation

func solution(_ n:Int) -> Int {
    
    var ans = 0
    if n % 2 != 0{
        for i in 0...n{
            if i % 2 != 0{
                ans += i
            }
        }
    }
    else{
        for i in 0...n{
            if i % 2 == 0{
                ans += i * i
            }
        }
    }
    
    return ans
}