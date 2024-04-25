import Foundation

func solution(_ arr:[Int], _ flag:[Bool]) -> [Int] {
    
    var ans : [Int] = []
    for i in 0..<flag.count{
        if flag[i]{
            for j in 0..<arr[i] * 2{
                ans.append(arr[i])
            }
        }
        else{
            let endIdx = ans.count - arr[i]
            if endIdx >= 0{
                for j in 0..<arr[i]{
                    ans.removeLast()
                }
            }
        }
    }
    
    return ans
}