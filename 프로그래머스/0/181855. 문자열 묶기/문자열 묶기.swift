import Foundation

func solution(_ strArr:[String]) -> Int {
    
    var arr = [Int : Int]()
    
    for str in strArr{
        arr[str.count, default : 0] += 1
    }
    
    if let Max = arr.values.max(){
        return Max
    }
    
    return 0
}