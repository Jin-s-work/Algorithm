import Foundation

func solution(_ array:[Int], _ n:Int) -> Int {
    
    var arr = array
    arr.sort(by : <)
    var Min = Int.max
    var ans = n
    for k in arr{
        if abs(n - k) < Min{
            Min = abs(n - k)
            ans = k
        }
    }
    
    return ans
}