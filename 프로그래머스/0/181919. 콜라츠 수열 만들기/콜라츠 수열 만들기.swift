import Foundation

func solution(_ n:Int) -> [Int] {
    
    var ans : [Int] = [n]
    var num = n
    while num != 1{
        if num % 2 == 0{
            num /= 2
        }
        else{
            num = 3 * num + 1
        }
        ans.append(num)
    }
    
    return ans
}