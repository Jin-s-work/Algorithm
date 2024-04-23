import Foundation

func solution(_ num_list:[Int]) -> Int {
    
    for (i, num) in num_list.enumerated(){
        if num < 0{
            return i
        }
    }
    
    return -1
}