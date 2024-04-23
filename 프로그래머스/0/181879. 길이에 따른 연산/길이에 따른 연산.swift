import Foundation

func solution(_ num_list:[Int]) -> Int {
    
    var ans = 1
    if num_list.count >= 11{
        ans = num_list.reduce(0, +)
    }
    else{
        for k in num_list{
            ans *= k
        }
    }
    
    return ans
}