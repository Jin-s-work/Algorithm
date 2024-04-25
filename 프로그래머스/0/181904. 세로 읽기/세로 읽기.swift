import Foundation

func solution(_ my_string:String, _ m:Int, _ c:Int) -> String {
    
    var ans = ""
    for i in 0..<my_string.count{
        if i % m == c-1{
            let idx = my_string.index(my_string.startIndex, offsetBy : i)
            ans.append(my_string[idx])
        }
    }
    
    return ans
}