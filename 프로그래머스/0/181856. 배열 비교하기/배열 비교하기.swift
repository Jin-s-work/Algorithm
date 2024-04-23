import Foundation

func solution(_ arr1:[Int], _ arr2:[Int]) -> Int {
    
    var ans = 0
    if arr1.count > arr2.count{
        ans = 1
    }
    else if arr1.count < arr2.count{
        ans = -1
    }
    else{
        if arr1.reduce(0, +) < arr2.reduce(0, +){
            ans = -1
        }
        else if arr1.reduce(0, +) > arr2.reduce(0, +){
            ans = 1
        }
        else{
            ans = 0
        }
    }
    
    
    return ans
}