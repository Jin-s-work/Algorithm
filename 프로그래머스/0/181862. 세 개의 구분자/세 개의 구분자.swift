import Foundation

func solution(_ myStr:String) -> [String] {
    
    var ans : [String] = []
    var st = ""
    for k in myStr{
        if k == "a" || k == "b" || k == "c"{
            if st != ""{
                ans.append(st)
            }
            st = ""
        }
        else{
            st += String(k)
        }
    }
    ans.append(st)
    
    if ans.count == 1 && ans[0] == ""{
        return ["EMPTY"]
    }
    
    return ans
}