import Foundation

func solution(_ cipher:String, _ code:Int) -> String {
    
    var st = ""
    for (i, char) in cipher.enumerated() {
        if (i + 1) % code == 0{
            st.append(char)
        }
    }
    
    return st
}