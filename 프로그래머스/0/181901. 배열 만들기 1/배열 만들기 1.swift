import Foundation

func solution(_ n:Int, _ k:Int) -> [Int] {
    
    var ans : [Int] = []
    for i in 1...n{
        if i % k == 0{
            ans.append(i)
        }
    }
    
    
    return ans
}