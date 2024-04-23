import Foundation

func solution(_ my_string:String, _ index_list:[Int]) -> String {
    
    var ans = ""
    for k in index_list{
        let idx = my_string.index(my_string.startIndex, offsetBy : k)
        ans.append(my_string[idx])
    }
    
    return ans
}