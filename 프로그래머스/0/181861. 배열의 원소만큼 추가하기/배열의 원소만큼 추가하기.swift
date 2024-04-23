import Foundation

func solution(_ arr:[Int]) -> [Int] {
    
    var ans : [Int] = []
    for k in arr{
        for i in 0..<k{
            ans.append(k)
        }
    }
    
    return ans
}