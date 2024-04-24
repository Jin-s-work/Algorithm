import Foundation

func solution(_ my_string:String) -> [String] {
    
    var ans : [String] = []
    for i in 0..<my_string.count{
        let startindex = my_string.index(my_string.startIndex, offsetBy : i)
        ans.append(String(my_string[startindex...]))
    }
    ans.sort(by: <)
    
    return ans
}