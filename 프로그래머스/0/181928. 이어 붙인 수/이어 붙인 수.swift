import Foundation

func solution(_ num_list:[Int]) -> Int {
    
    var odd = ""
    var even = ""
    
    for k in num_list{
        if k % 2 == 0{
            even.append(String(k))
        }
        else{
            odd.append(String(k))
        }
    }
    
    let oddSum = Int(odd) ?? 0
    let evenSum = Int(even) ?? 0
    
    return oddSum + evenSum
}