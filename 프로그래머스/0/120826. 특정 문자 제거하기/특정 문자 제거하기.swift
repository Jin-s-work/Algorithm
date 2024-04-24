import Foundation

func solution(_ my_string:String, _ letter:String) -> String {
    
    var ans = ""
    for k in my_string{
        if String(k) == letter{
            continue
        }
        else{
            ans.append(String(k))
        }
    }
    
    return ans
}