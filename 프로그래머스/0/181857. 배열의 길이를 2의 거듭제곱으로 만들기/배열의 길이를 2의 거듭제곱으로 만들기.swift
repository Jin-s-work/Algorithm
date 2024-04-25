import Foundation

func solution(_ arr:[Int]) -> [Int] {
    
    var ans : [Int] = []
    ans = arr
    var n = arr.count
    if n == 0 || n == 1{
        return arr
    }
    
    let log = Int(ceil(log2(Double(n))))
    let num = Int(pow(2, Double(log))) - n
    
    for i in 0..<num{
        ans.append(0)
    }
    
    
    
    return ans
}