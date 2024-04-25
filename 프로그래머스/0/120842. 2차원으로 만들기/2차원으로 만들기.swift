import Foundation

func solution(_ num_list:[Int], _ n:Int) -> [[Int]] {
    
    var ans : [[Int]] = []
    var arr : [Int] = []
    for i in 0..<num_list.count{
        
        if i % n == 0 && i != 0{
            ans.append(arr)
            arr = []
        }
        arr.append(num_list[i])
        
    }
    ans.append(arr)
    
    return ans
}