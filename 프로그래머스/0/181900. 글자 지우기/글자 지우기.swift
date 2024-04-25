import Foundation

func solution(_ my_string:String, _ indices:[Int]) -> String {
    
    let arr = Array(indices)
    var ans = ""
    for (i, num) in my_string.enumerated(){
        if !arr.contains(i){
            ans.append(num)
        }
    }
    
    return ans
}