import Foundation

func solution(_ num_str:String) -> Int {
    
    var ans = 0
    for k in num_str{
        if let num = Int(String(k)){
            ans += num
        }
    }
    
    return ans
}