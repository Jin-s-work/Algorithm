import Foundation

func solution(_ num_list:[Int], _ n:Int) -> [Int] {
    
    var ans : [Int] = []
    
    for (i, num) in num_list.enumerated(){
        if i >= n{
            ans.append(num)
        }
    }
    for (i, num) in num_list.enumerated(){
        if i < n{
            ans.append(num)
        }
    }
    
    return ans
}