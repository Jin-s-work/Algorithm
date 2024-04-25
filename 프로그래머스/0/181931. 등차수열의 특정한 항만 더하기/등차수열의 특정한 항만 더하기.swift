import Foundation

func solution(_ a:Int, _ d:Int, _ included:[Bool]) -> Int {
    
    var ans = 0
    var num = a
    for i in 0..<included.count{
        if included[i]{
            ans += num
        }
        num += d
    }
    
    return ans
}