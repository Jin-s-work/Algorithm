import Foundation

func solution(_ arr:[Int]) -> [Int] {
    
    var ans : [Int] = []
    
    for k in arr{
        if k >= 50 && k % 2 == 0{
            ans.append(k / 2)
        }
        else if k < 50 && k % 2 != 0{
            ans.append(k * 2)
        }
        else{
            ans.append(k)
        }
    }
    
    return ans
}