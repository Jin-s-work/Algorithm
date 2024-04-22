import Foundation

func solution(_ my_string:String) -> String {
    
    var st = ""
    for k in my_string{
        if k >= "a" && k <= "z"{
            st.append(k.uppercased())
        }
        else{
            st.append(k.lowercased())
        }
    }
    
    return st
}