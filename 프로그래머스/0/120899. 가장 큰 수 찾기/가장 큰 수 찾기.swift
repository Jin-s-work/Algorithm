import Foundation

func solution(_ array:[Int]) -> [Int] {
    
    var Max = array[0]
    var Maxidx = 0
    
    for (idx, num) in array.enumerated(){
        if num > Max{
            Max = num
            Maxidx = idx
        }
    }

    return [Max, Maxidx]
}