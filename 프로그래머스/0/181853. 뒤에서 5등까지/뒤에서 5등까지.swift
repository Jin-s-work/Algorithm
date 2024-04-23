import Foundation

func solution(_ num_list:[Int]) -> [Int] {
    
    var ans : [Int] = []
    var arr = num_list
    arr.sort()
    for i in 0..<5{
        ans.append(arr[i])
    }
    
    return ans
}