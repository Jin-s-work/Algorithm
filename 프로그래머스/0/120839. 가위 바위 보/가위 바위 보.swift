import Foundation

func solution(_ rsp:String) -> String {
    
    var st = ""
    for k in rsp{
        if k == "2"{
            st.append("0")
        }
        else if k == "0"{
            st.append("5")
        }
        else if k == "5"{
            st.append("2")
        }
    }
    
    return st
}