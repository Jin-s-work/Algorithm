import Foundation

func solution(_ numbers:[Int]) -> Int {
    
    var arr = numbers
    arr.sort()
    
    var ans = 0
    if arr[0] * arr[1] < arr[arr.count - 2] * arr[arr.count - 1]{
        ans = arr[arr.count - 2] * arr[arr.count - 1]
    }
    else{
        ans = arr[0] * arr[1]
    }
    
    
    
    return ans
}