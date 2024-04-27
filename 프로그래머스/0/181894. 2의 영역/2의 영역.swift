import Foundation

func solution(_ arr:[Int]) -> [Int] {
    
    if !arr.contains(2){
        return [-1]
    }
    
    var start = 100001
    var end = 0
    for (idx, num) in arr.enumerated(){
        if num == 2{
            if idx < start{
                start = idx
            }
            if idx > end{
                end = idx
            }
        }
    }
    var ans : [Int] = []
    for i in start...end{
        ans.append(arr[i])
    }
    
    return ans
}