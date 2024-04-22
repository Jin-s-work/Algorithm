import Foundation

func solution(_ my_string:String) -> String {
    
    var st = ""
    for k in my_string{
        if k != "a" && k != "e" && k != "i" && k != "o" && k != "u"{
            st.append(k)
        }
    }
    
    return st
}