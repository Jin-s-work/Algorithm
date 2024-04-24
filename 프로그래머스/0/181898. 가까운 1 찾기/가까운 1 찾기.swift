import Foundation

func solution(_ arr:[Int], _ idx:Int) -> Int {
    
    var ans = -1
    for (i, num) in arr.enumerated(){
        if i >= idx && num == 1{
            ans = i
            break
        }
    }
    
    return ans
}