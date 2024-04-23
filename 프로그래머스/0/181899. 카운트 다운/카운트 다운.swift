import Foundation

func solution(_ start:Int, _ end_num:Int) -> [Int] {
    
    var ans : [Int] = []
    for num in stride(from:start, to: end_num-1, by : -1){
        ans.append(num)
    }
    
    return ans
}