import Foundation

func solution(_ numbers:[Int]) -> [Int] {
    
    var arr: [Int] = []
    for k in numbers{
        arr.append(k * 2)
    }
    
    return arr
}