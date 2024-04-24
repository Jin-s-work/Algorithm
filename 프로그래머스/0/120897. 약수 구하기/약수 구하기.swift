import Foundation

func solution(_ n:Int) -> [Int] {
    
    var ans : [Int] = []
    for i in 1...n{
        if n % i == 0{
            ans.append(i)
        }
    }
    
    return ans
}