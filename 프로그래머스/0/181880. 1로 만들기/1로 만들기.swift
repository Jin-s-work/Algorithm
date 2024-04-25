import Foundation

func solution(_ num_list:[Int]) -> Int {
    
    var ans = 0
    for k in num_list{
        var num = k
        while num != 1{
            if num % 2 == 0{
                num /= 2
            }
            else{
                num -= 1
                num /= 2
            }
            ans += 1
        }
    }
     
    
    return ans
}