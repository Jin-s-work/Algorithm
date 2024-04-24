import Foundation

func solution(_ arr:[Int], _ delete_list:[Int]) -> [Int] {
    
    var ans : [Int] = []
    for k in arr{
        if !delete_list.contains(k){
            ans.append(k)
        }
    }
    
    return ans
}