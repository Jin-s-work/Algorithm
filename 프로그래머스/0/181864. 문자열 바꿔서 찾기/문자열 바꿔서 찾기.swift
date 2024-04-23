import Foundation

func solution(_ myString:String, _ pat:String) -> Int {
    
    var st = ""
    for k in myString{
        if k == "A"{
            st.append("B")
        }
        else if k == "B"{
            st.append("A")
        }
        else{
            st.append(String(k))
        }
    }
    
    if st.contains(pat){
        return 1
    }
    else{
        return 0
    }
    
    
    return 1
}