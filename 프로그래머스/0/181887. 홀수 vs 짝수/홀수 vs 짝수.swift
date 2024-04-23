import Foundation

func solution(_ num_list:[Int]) -> Int {
    
    var even = 0
    var odd = 0
    for (i, num) in num_list.enumerated(){
        if i % 2 == 0{
            even += num
        }
        else{
            odd += num
        }
    }
    var ans = 0
    if odd >= even{
        return odd
    }
    else{
        return even
    }
    
    
    return 0
}