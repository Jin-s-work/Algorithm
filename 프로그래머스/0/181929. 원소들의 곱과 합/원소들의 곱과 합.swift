import Foundation

func solution(_ num_list:[Int]) -> Int {
    
    var mul = 1
    var add = 0
    for k in num_list{
        add += k
        mul *= k
    }
    
    if add * add > mul{
        return 1
    }
    else{
        return 0
    }
    
    return 0
}