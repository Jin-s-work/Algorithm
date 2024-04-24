import Foundation

func solution(_ arr:[Int], _ k:Int) -> [Int] {
    
    var ans : [Int] = []
    if k % 2 == 0{
        for num in arr{
            ans.append(k + num)
        }
    }
    else{
        for num in arr{
            ans.append(num * k)
        }
    }
    
    return ans
}